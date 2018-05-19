#!/bin/bash


# download and compile ODB compiler, ODB runtime library, and sqlite DB plugin for ODB
#if [ ! -f "odb/libodb.a" ]; then
  mkdir -p odb && cd odb
  wget http://codesynthesis.com/download/odb/2.4/libodb-2.4.0.tar.bz2 -O /tmp/libodb.tar.bz2
  tar jxvf /tmp/libodb.tar.bz2
  cd libodb-2.4.0 && ./configure && make && make install && cd ..

  wget http://codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.tar.bz2 -O /tmp/libodb-sqlite.tar.bz2
  tar jxvf /tmp/libodb-sqlite.tar.bz2
  cd libodb-sqlite-2.4.0 && ./configure --with-libodb=../libodb-2.4.0 && make && make install && cd ..


  # make easier to find the static libraries
  cp libodb-2.4.0/odb/.libs/libodb.a .
  cp libodb-sqlite-2.4.0/odb/sqlite/.libs/libodb-sqlite.a .

  cp libodb-2.4.0/odb/.libs/libodb.dylib .
  cp libodb-sqlite-2.4.0/odb/sqlite/.libs/libodb-sqlite.dylib .

  # crt0.o
  cd ../dependencies_mac/Csu-85/
  make
  cp crt0.o ../../odb/

  cd ../../
  echo "downloaded odb:"
  ls odb

#else
#  echo "skipping odb installation: odb directory found:"
#  ls odb
#fi

