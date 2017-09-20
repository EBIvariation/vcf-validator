FROM debian:stretch-slim

RUN apt-get update -y && apt-get install -y --no-install-recommends \
g++ \
make \
cmake \
libboost-dev \
libboost-filesystem-dev \
libboost-program-options-dev \
libboost-regex-dev \
libsqlite3-dev \
ragel \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/* /usr/share/doc /usr/share/doc-base

# update needed again, as it was removed before; it fetches less than 1 mb
RUN apt-get update && apt-get install -y --no-install-recommends wget bzip2 \
&& wget http://www.codesynthesis.com/download/odb/2.4/odb_2.4.0-1_amd64.deb -O /opt/odb_2.4.0-1_amd64.deb \
&& wget http://codesynthesis.com/download/odb/2.4/libodb-2.4.0.tar.bz2 -O /opt/libodb.tar.bz2 \
&& wget http://codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.tar.bz2 -O /opt/libodb-sqlite.tar.bz2 \
&& cd /opt && tar jxvf libodb.tar.bz2 && tar jxvf libodb-sqlite.tar.bz2 && dpkg -i odb_2.4.0-1_amd64.deb \
&& cd libodb-2.4.0 && ./configure && make && make install && cd .. \
&& cd libodb-sqlite-2.4.0 && ./configure --with-libodb=../libodb-2.4.0 && make && make install && cd .. \
&& apt-get clean && apt-get remove --purge -y wget bzip2 \
&& rm -rf /opt /var/lib/apt/lists/* /usr/share/doc /usr/share/doc-base

COPY ./entrypoint.sh /
CMD ["/entrypoint.sh"]
