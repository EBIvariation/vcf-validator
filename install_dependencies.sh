#!/bin/bash


help_install_dependencies="
Usage:
./install_dependencies.sh [os_name]      default OS is linux
os_name can be:
    linux
    osx
example for mac os:
./install_dependencies.sh osx
"

if [ "$#" -eq 0 ]
then
    OS_NAME="linux"
elif [ "$#" -eq 1 ]
then
  if [[ "$1" == "linux" ]]
  then
  OS_NAME="linux"
  elif [[ "$1" == "osx" ]]
  then
  OS_NAME="osx"
  else
    echo "$help_install_dependencies"
    exit
  fi
else
  echo "requires 1 argument at max"
  echo "$help_install_dependencies"
  exit
fi


# download and compile ODB compiler, ODB runtime library, and sqlite DB plugin for ODB
if [ ! -d "odb/odb-2.4.0-x86_64-linux-gnu" ]; then
  mkdir -p odb && cd odb

  echo "installing libodb"
  wget http://codesynthesis.com/download/odb/2.4/libodb-2.4.0.tar.bz2 -O /tmp/libodb.tar.bz2
  tar jxvf /tmp/libodb.tar.bz2
  cd libodb-2.4.0 && ./configure && make && cd ..

  echo "installing libodb-sqlite"
  wget http://codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.tar.bz2 -O /tmp/libodb-sqlite.tar.bz2
  tar jxvf /tmp/libodb-sqlite.tar.bz2
  cd libodb-sqlite-2.4.0 && ./configure --with-libodb=../libodb-2.4.0 && make && cd ..

  # make easier to find the static libraries
  cp libodb-2.4.0/odb/.libs/libodb.a .
  cp libodb-sqlite-2.4.0/odb/sqlite/.libs/libodb-sqlite.a .

  if [[ "$OS_NAME" == "linux" ]]
  then
    cp libodb-2.4.0/odb/.libs/libodb.so .
    cp libodb-sqlite-2.4.0/odb/sqlite/.libs/libodb-sqlite.so .


    wget http://codesynthesis.com/download/odb/2.4/odb-2.4.0-x86_64-linux-gnu.tar.bz2 -O /tmp/odb.tar.bz2
    tar jxvf /tmp/odb.tar.bz2
  elif [[ "$OS_NAME" == "osx" ]]
  then
    cp libodb-2.4.0/odb/.libs/libodb.dylib .
    cp libodb-sqlite-2.4.0/odb/sqlite/.libs/libodb-sqlite.dylib .


    wget http://codesynthesis.com/download/odb/2.4/odb-2.4.0-i686-macosx.tar.bz2 -O /tmp/odb.tar.bz2
    tar jxvf /tmp/odb.tar.bz2
  else
    echo "Invalid OS name"
    echo "$help_install_dependencies"
    exit
  fi


  cd ..
  echo "downloaded odb:"
  ls odb

else
  echo "skipping odb installation: odb directory found:"
  ls odb
fi
