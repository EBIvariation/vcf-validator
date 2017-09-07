#!/bin/bash


# download and compile ODB compiler, ODB runtime library, and sqlite DB plugin for ODB
if [ ! -d "odb/odb-2.4.0-x86_64-linux-gnu" ]; then
  mkdir -p odb && cd odb
  wget http://codesynthesis.com/download/odb/2.4/odb-2.4.0-x86_64-linux-gnu.tar.bz2 -O /tmp/odb.tar.bz2
  tar jxvf /tmp/odb.tar.bz2
  # the odb compiler is already available as binary: no configure && make

  wget http://codesynthesis.com/download/odb/2.4/libodb-2.4.0.tar.bz2 -O /tmp/libodb.tar.bz2
  tar jxvf /tmp/libodb.tar.bz2
  cd libodb-2.4.0 && ./configure && make && cd ..

  wget http://codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.tar.bz2 -O /tmp/libodb-sqlite.tar.bz2
  tar jxvf /tmp/libodb-sqlite.tar.bz2
  cd libodb-sqlite-2.4.0 && ./configure --with-libodb=../libodb-2.4.0 && make && cd ..
  cd ..

  # make easier to find the static libraries
  cp libodb-2.4.0/odb/.libs/libodb.a .
  cp libodb-sqlite-2.4.0/odb/sqlite/.libs/libodb-sqlite.a .
else
  echo "skipping odb installation: odb directory found:"
  ls odb
fi

