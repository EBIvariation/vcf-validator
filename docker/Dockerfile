FROM alpine:3.6

RUN apk upgrade && apk update && apk add \
g++ \
make \
cmake \
boost-dev \
boost-filesystem \
boost-program_options \
boost-regex \
sqlite-dev \
ragel \
wget

RUN mkdir /opt
RUN wget http://www.codesynthesis.com/download/odb/2.4/odb-2.4.0.tar.bz2 -O /opt/odb.tar.bz2
RUN wget http://codesynthesis.com/download/odb/2.4/libodb-2.4.0.tar.bz2 -O /opt/libodb.tar.bz2
RUN wget http://codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.tar.bz2 -O /opt/libodb-sqlite.tar.bz2

# ODB compiler
RUN cd /opt && tar jxvf odb.tar.bz2 && tar jxvf libodb.tar.bz2 && tar jxvf libodb-sqlite.tar.bz2
RUN cd /opt/libodb-2.4.0 && ./configure && make && make install
RUN cd /opt/libodb-sqlite-2.4.0 && ./configure --with-libodb=../libodb-2.4.0 && make && make install

COPY ./entrypoint.sh /
CMD ["/entrypoint.sh"]
