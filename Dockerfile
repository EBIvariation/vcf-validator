# This is a image for building vcf_validator tool.  The resulting binary is staticly linked,
# so it is portable to other linux variants.
#
# Notable changes from simply using install_dependencie.sh:
#
#   + using odb v2.5.0-b.23 as that has adjustments so can compile on arm64
#   + building odb via build2
#   + had to add '-Wno-narrowing' to compilation step to avoid errors (doesn't appear to break anything; test pass)
#   + libz, libbz2, libboost-* installed via apt

FROM debian:11-slim as build

ARG VCF_VALIDATOR_VERSION
ARG ODB_VERSION=2.5.0-b.23
ARG BUILD2_VERSION=0.15.0

# Linux tools 
RUN apt-get update && apt-get upgrade --yes && \
    apt-get install --yes \
        bash \
        binutils-gold \
        build-essential \
        bzip2 \
        cmake \
        curl \
        file \
        findutils \
        g++ \
        gcc \
        gcc-10-plugin-dev \
        git \
        libboost-dev \
        libboost-filesystem-dev \
        libboost-iostreams-dev \
        libboost-program-options-dev \
        libboost-regex-dev \
        libboost-log-dev \
        libc-dev \
        libbz2-dev \
        libgmp-dev \
        libffi-dev \
        libsqlite3-0 \
        libsqlite3-dev \
        make \
        musl-dev \
        perl \
        ripgrep \
        sqlite3 \
        sudo \
        vim \
        wget  \
        zlib1g-dev

# Patch x86 bug (missing header file) https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=980609
COPY docker/gcc-x86.patch /gcc-x86.patch
RUN if [ "$(uname -m)" = "x86_64" ] ; then \
       cd / && patch -p1 < /gcc-x86.patch && rm /gcc-x86.patch; \
    fi

# build2 https://build2.org/install.xhtml#unix
# This is required to build the latest version of odb, which has multi-arch support
RUN set -eux; \
    url="https://download.build2.org/${BUILD2_VERSION}/build2-install-${BUILD2_VERSION}.sh"; \
    sha256='814c4f475b42749dab49c52549ef85899749c20e5c32276b281fd58dad54f47b'; \
    mkdir -p /build/build2; \
    cd /build/build2; \
    curl -sSfO "$url"; \
    echo "$sha256  build2-install-${BUILD2_VERSION}.sh" | sha256sum -cw -; \
    sh build2-install-${BUILD2_VERSION}.sh --local --yes

# odb binary https://codesynthesis.com/products/odb/doc/install-build2.xhtml
RUN set -eux; \
    mkdir -p /build/odb; \
    cd /build/odb; \
    bpkg create -d odb-gcc-10 cc  \
         config.cxx=g++ \
         config.cc.coptions=-O3 \
         config.install.root=/usr/local \
         config.install.sudo=sudo; \
    cd odb-gcc-10; \
    bpkg --trust-yes build odb/${ODB_VERSION}@https://pkg.cppget.org/1/beta --yes; \
    bpkg install odb

# odb library
RUN set -eux; \
    cd /build/odb; \
    bpkg create -d libodb-gcc-10 cc  \
         config.cxx=g++ \
         config.cc.coptions=-O3 \
         config.install.root=/usr/local \
         config.install.sudo=sudo; \
    cd libodb-gcc-10; \
    bpkg add https://pkg.cppget.org/1/beta ;\
    bpkg --trust-yes fetch ;\
    bpkg --trust-yes build libodb/${ODB_VERSION} ;\
    bpkg --trust-yes build libodb-sqlite/${ODB_VERSION} --yes ;\
    bpkg --trust-yes build libodb-boost/${ODB_VERSION} ;\
    bpkg install --all --recursive

# vcf_validator https://github.com/EBIvariation/vcf-validator/tree/v0.9.4
RUN cd /build && \
    git clone --depth 1 --branch v${VCF_VALIDATOR_VERSION} https://github.com/EBIvariation/vcf-validator.git

# FYI: Alternative to above - copy current working dir:
#COPY . /build/vcf-validator

# copy + run our modified install-dependencies-docker.sh script
COPY docker/install-dependencies-docker.sh /build/vcf-validator/install-dependencies-docker.sh
RUN cd /build/vcf-validator && ./install-dependencies-docker.sh

# Fix path to odb, add -Wno-narrowing to enable build to work
# we put everything in the root of EXT_LIB_PATH (linux_dependencies)
RUN sed -i -e 's|${EXT_LIB_PATH}/odb-2.4.0-x86_64-linux-gnu/bin/|/usr/local/bin/|' \
           -e 's|-Wall -Wno-unknown-pragmas|-Wall -Wno-unknown-pragmas -Wno-narrowing|' \
        /build/vcf-validator/CMakeLists.txt

# Fix ODB_VERSION since we are using latest
RUN sed -i -e 's|ODB_VERSION != 20400UL|ODB_VERSION != 20473UL|' \
        /build/vcf-validator/inc/vcf/error-odb.hpp

# Copy libraries to the place the CMakeLists.txt expects them
RUN arch=$(uname -m); \
    cd /build/vcf-validator/linux_dependencies; \
    cp /usr/local/lib/*.a .; \
    cp /usr/lib/${arch}-linux-gnu/*.a .;

# Build vcf and validate build worked with 'make test'
RUN set -eux; \
    cd /build/vcf-validator; \
    mkdir build && cd build && cmake -G "Unix Makefiles" ..; \
    make; \
    ln -s ../test test; \
    CTEST_OUTPUT_ON_FAILURE=1 make test;

# Copy binaries to root
RUN cd /build/vcf-validator/build; \
    cp bin/vcf_validator /; \
    cp bin/vcf_debugulator /; \
    cp bin/vcf_assembly_checker /; \
    cp bin/test_validation_suite /;

# Since it is statically linked, can have just the executables in the final image
FROM scratch

COPY --from=build /vcf_validator /
COPY --from=build /vcf_debugulator /
COPY --from=build /vcf_assembly_checker /
COPY --from=build /test_validation_suite /

ENTRYPOINT ["/vcf_validator"]
