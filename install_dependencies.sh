#!/bin/bash

# stop the script if any command fails
set -e

# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'if [ $? -ne 0 ]; then echo "******ERROR******: \"${last_command}\" command failed with exit code $?." && echo "Installation of dependencies failed!"; fi' EXIT

########################################
#    Dependency Version Parameters
########################################
BZ2_VERSION="1.0.6"
ZLIB_VERSION="1.3.1"
OPENSSL_VERSION="1.1.1w"
CARES_VERSION="1.15.0"
CURL_VERSION="7.62.0"
BOOST_VERSION="1.81.0"

########################################
#   Help / Usage
########################################
help_install_dependencies="Usage:
./install_dependencies.sh                   installs dependencies for Linux OS

it installs the given dependencies:
  - bzip library                            bzip2-${BZ2_VERSION}
  - zlib library                            zlib-${ZLIB_VERSION}
  - curl library                            curl-${CURL_VERSION}
  - openssl library                         openssl-${OPENSSL_VERSION}
  - c-ares library                          c-ares-${CARES_VERSION}
  - boost library                           boost-${BOOST_VERSION}
"

########################################
#   OS Check
########################################
if [ "$#" -ne 0 ]; then
  echo "$help_install_dependencies"
  exit 1
else
  OS_NAME=$(uname)
  if [[ $OS_NAME != "Linux" ]]; then
    echo -e "\nThis script is to be executed only for Linux."
    echo "$help_install_dependencies"
    exit 1
  fi
fi

dependencies_dir="dependencies"

if [ "$(ls -A $dependencies_dir 2>/dev/null)" ]; then
  echo "ERROR: Found non-empty directory of a previous installation: \"$dependencies_dir\". Please remove the folder before running this script. Current contents:"
  ls $dependencies_dir
  exit 1
fi

echo "Creating directory $dependencies_dir"
mkdir -p "$dependencies_dir" && cd "$dependencies_dir"

dependencies_dir_abs_path=$(pwd)
build_dir_abs_path="${dependencies_dir_abs_path}/build"
mkdir "$build_dir_abs_path"
lib_dir_abs_path="${build_dir_abs_path}/lib"
include_dir_abs_path="${build_dir_abs_path}/include"
PKG_CONFIG_PATH="${lib_dir_abs_path}/pkgconfig"

########################################
#   Install Dependencies
########################################

# libbz2
echo "Installing libbz2"
wget --no-check-certificate https://sourceware.org/pub/bzip2/bzip2-${BZ2_VERSION}.tar.gz -O ./libbz2.tar.gz
tar xzf ./libbz2.tar.gz
cd bzip2-${BZ2_VERSION} && make && make install PREFIX=$build_dir_abs_path
cd ..

# zlib
echo "Installing zlib"
wget --no-check-certificate https://zlib.net/zlib-${ZLIB_VERSION}.tar.gz -O ./libz.tar.gz
tar xzf ./libz.tar.gz
# sharedlibdir is set elsewhere so that the .so file is not being used when linking
cd zlib-${ZLIB_VERSION} && ./configure --prefix=$build_dir_abs_path --sharedlibdir=$dependencies_dir_abs_path && make install
cd ..

# openssl
echo "Installing OpenSSL"
wget --no-check-certificate "https://www.openssl.org/source/openssl-${OPENSSL_VERSION}.tar.gz" -O ./openssl.tar.gz
tar xzf ./openssl.tar.gz
cd "openssl-${OPENSSL_VERSION}"
LIBS="-lcrypto -ldl" ./config -static --static -fPIC no-shared no-threads --prefix=$build_dir_abs_path --openssldir=$build_dir_abs_path
make && make install_sw
cd ..

# c-ares
echo "Installing c-ares"
wget --no-check-certificate "https://github.com/c-ares/c-ares/releases/download/cares-${CARES_VERSION//./_}/c-ares-${CARES_VERSION}.tar.gz" -O ./c-ares.tar.gz
tar xzf ./c-ares.tar.gz
cd "c-ares-${CARES_VERSION}" && ./configure --prefix=$build_dir_abs_path --disable-shared --enable-static && make && make install
cd ..

# curl
echo "Installing libcurl"
wget --no-check-certificate "https://curl.haxx.se/download/curl-${CURL_VERSION}.tar.gz" -O ./curl.tar.gz
tar zxf ./curl.tar.gz
cd "curl-${CURL_VERSION}"
LDFLAGS="-L${lib_dir_abs_path}" CPPFLAGS="-I$include_dir_abs_path" \
./configure --disable-shared --enable-static --without-librtmp \
  --without-ca-bundle --disable-ldap --without-zlib --without-libidn2 \
  --without-nss --enable-ares=$build_dir_abs_path --with-ssl=$build_dir_abs_path  \
  --prefix=$build_dir_abs_path
make && make install
cd ..

# Boost
echo "Installing Boost"
wget --no-check-certificate "https://sourceforge.net/projects/boost/files/boost/${BOOST_VERSION}/boost_${BOOST_VERSION//./_}.tar.gz/download" -O ./boost.tar.gz
tar zxf ./boost.tar.gz
mv "boost_${BOOST_VERSION//./_}" boost && cd boost
## Boost custom config
#echo "
#using zlib : ${ZLIB_VERSION} : <source>${dependencies_dir_abs_path}/zlib-${ZLIB_VERSION} ;
#using bzip2 : ${BZ2_VERSION} : <source>${dependencies_dir_abs_path}/bzip2-${BZ2_VERSION} ;
#" > tools/build/src/user-config.jam
./bootstrap.sh --prefix=${build_dir_abs_path} --with-libraries=filesystem,iostreams,log,program_options,regex,system,thread
./b2 \
  link=static \
  runtime-link=static \
  threading=multi \
  variant=release \
  cxxflags="-std=c++14 -fPIC" \
  --with-filesystem \
  --with-iostreams \
  --with-program_options \
  --with-regex \
  --with-log \
  --with-thread \
  --with-system \
  --prefix=${build_dir_abs_path} \
  -sBZIP2_INCLUDE=${include_dir_abs_path} \
  -sBZIP2_LIBPATH=${lib_dir_abs_path} \
  -sZLIB_INCLUDE=${include_dir_abs_path}   \
  -sZLIB_LIBPATH=${lib_dir_abs_path} \
  -sCARES_INCLUDE=${include_dir_abs_path}   \
  -sCARES_LIBPATH=${lib_dir_abs_path} \
  install

cd ..
cd ..

echo "Dependencies folder:"
ls "$build_dir_abs_path"

echo -e "\nAutomatic installation completed successfully."
