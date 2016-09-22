FROM ubuntu:xenial

RUN apt-get update -y && apt-get upgrade -y && apt-get install -y \
build-essential \
cmake \
libboost-dev \
libboost-filesystem-dev \
libboost-program-options-dev \
libboost-regex-dev \
odb \
libodb-dev \
libodb-sqlite-dev \
libsqlite3-dev

COPY ./entrypoint.sh /
CMD ["/entrypoint.sh"]
