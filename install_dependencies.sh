#!/bin/bash

set -e

help_install_dependencies="Usage:
./install_dependencies.sh [os_name]         default OS is linux
./install_dependencies.sh --help            displays help

os_name can be:
  - linux
  - osx

it installs the given dependencies:
  - odb compiler                            odb-2.4.0
  - odb common runtime library              libodb-2.4.0
  - odb sqlite runtime library              libodb-sqlite-2.4.0
  - bzip library                            bzip2-1.0.6
  - zlib library                            zlib-1.2.11
  - curl library                            curl-7.62.0
  - openssl library                         openssl-1.1.1a
  - c-ares library                          c-ares-1.15.0

for linux:
./install_dependencies.sh linux

for mac os:
./install_dependencies.sh osx
"

INSTALL_FAILED=0

if [ "$#" -eq 0 ]
then
    OS_NAME="linux"
elif [ "$#" -eq 1 ]
then
  if [[ "$1" == "--help" ]]
  then
      echo "$help_install_dependencies"
      exit
  elif [[ "$1" == "linux" ]]
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

dependencies_dir=$OS_NAME"_dependencies"

#check for already downloaded files
if [ -d "$dependencies_dir/libodb-2.4.0" ]; then
  echo "skipping odb installation: $dependencies_dir directory found:"
  ls $dependencies_dir
  exit
fi


# Download ODB runtime library, sqlite DB plugin for ODB, libbz2 and libz.
echo "creating directory $dependencies_dir"
mkdir -p $dependencies_dir && cd $dependencies_dir

echo "installing libodb"
wget http://codesynthesis.com/download/odb/2.4/libodb-2.4.0.tar.bz2 -O /tmp/libodb.tar.bz2
tar jxf /tmp/libodb.tar.bz2
cd libodb-2.4.0 && ./configure && make
RESULT=$?
INSTALL_FAILED=$(( $INSTALL_FAILED + $RESULT ))
cd ..

echo "installing libodb-sqlite"
wget http://codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.tar.bz2 -O /tmp/libodb-sqlite.tar.bz2
tar jxf /tmp/libodb-sqlite.tar.bz2
cd libodb-sqlite-2.4.0 && ./configure --with-libodb=../libodb-2.4.0 && make
RESULT=$?
INSTALL_FAILED=$(( $INSTALL_FAILED + $RESULT ))
cd ..

echo "installing libbz2"
# This is commented till the bzip.org site is recovered.
# wget http://www.bzip.org/1.0.6/bzip2-1.0.6.tar.gz -O /tmp/libbz2.tar.gz
# tar zxf /tmp/libbz2.tar.gz
# Till then we can trust ubuntu archives.
wget http://archive.ubuntu.com/ubuntu/pool/main/b/bzip2/bzip2_1.0.6.orig.tar.bz2 -O /tmp/libbz2.tar.bz2
tar jxf /tmp/libbz2.tar.bz2
cd bzip2-1.0.6 && make
RESULT=$?
INSTALL_FAILED=$(( $INSTALL_FAILED + $RESULT ))
cd ..

echo "installing libz"
wget http://prdownloads.sourceforge.net/libpng/zlib-1.2.11.tar.gz?download -O /tmp/libz.tar.gz
tar zxf /tmp/libz.tar.gz
cd zlib-1.2.11 && cmake . && make
RESULT=$?
INSTALL_FAILED=$(( $INSTALL_FAILED + $RESULT ))
cd ..

dependencies_dir_abs_path=`pwd`

echo "installing openssl"
mkdir openssl
wget https://www.openssl.org/source/openssl-1.1.1a.tar.gz -O /tmp/openssl-1.1.1a.tar.gz
tar xzf /tmp/openssl-1.1.1a.tar.gz
cd openssl-1.1.1a
LIBS="-lcrypto -ldl" \
./config -fPIC no-shared no-threads \
        --prefix=$dependencies_dir_abs_path/openssl \
        --openssldir=$dependencies_dir_abs_path/openssl
make && make install_sw
RESULT=$?
INSTALL_FAILED=$(( $INSTALL_FAILED + $RESULT ))
cd ..

echo "installing c-ares"
mkdir c-ares
wget https://c-ares.haxx.se/download/c-ares-1.15.0.tar.gz -O /tmp/c-ares-1.15.0.tar.gz
tar xzf /tmp/c-ares-1.15.0.tar.gz
cd c-ares-1.15.0
./configure --prefix=$dependencies_dir_abs_path/c-ares
make && make install
RESULT=$?
INSTALL_FAILED=$(( $INSTALL_FAILED + $RESULT ))
cd ..

echo "installing libcurl"
mkdir curl
wget https://curl.haxx.se/download/curl-7.62.0.tar.gz -O /tmp/curl-7.62.0.tar.gz
tar zxf /tmp/curl-7.62.0.tar.gz
cd curl-7.62.0
LDFLAGS="-L$dependencies_dir_abs_path/openssl/lib -L$dependencies_dir_abs_path/c-ares/lib" \
CPPFLAGS="-I$dependencies_dir_abs_path/openssl/include -I$dependencies_dir_abs_path/c-ares/include" \
./configure --disable-shared \
            --enable-static \
            --without-librtmp \
            --without-ca-bundle \
            --disable-ldap \
            --without-zlib \
            --without-libidn2 \
            --without-nss \
            --enable-ares=$dependencies_dir_abs_path/c-ares \
            --with-ssl=$dependencies_dir_abs_path/openssl \
            --prefix=$dependencies_dir_abs_path/curl
make && make install
RESULT=$?
INSTALL_FAILED=$(( $INSTALL_FAILED + $RESULT ))
cd ..

if [[ "$OS_NAME" == "linux" ]]
then
  echo "installing  boost"
  wget https://dl.bintray.com/boostorg/release/1.65.1/source/boost_1_65_1.tar.gz -O /tmp/boost.tar.gz
  tar zxf /tmp/boost.tar.gz
  mv boost_1_65_1 boost && cd boost
  echo "
using zlib : 1.2.11 : <include>${dependencies_dir_abs_path}/zlib-1.2.11 <search>${dependencies_dir_abs_path}/ ;
using bzip2 : 1.0.6 : <include>${dependencies_dir_abs_path}/bzip2-1.0.6 <search>${dependencies_dir_abs_path}/ ;
" > tools/build/src/user-config.jam
  ./bootstrap.sh --with-libraries=filesystem,iostreams,log,program_options,regex && ./b2 link=static
  RESULT=$?
  INSTALL_FAILED=$(( $INSTALL_FAILED + $RESULT ))
  cd ..
fi


# Make easier to find the static libraries
cp libodb-2.4.0/odb/.libs/libodb.a .
cp libodb-sqlite-2.4.0/odb/sqlite/.libs/libodb-sqlite.a .
cp bzip2-1.0.6/libbz2.a .
cp zlib-1.2.11/libz.a .

# copy headers
cp -r libodb-2.4.0/odb ./
cp -r libodb-sqlite-2.4.0/odb/sqlite ./odb/

# Download odb compiler
if [[ "$OS_NAME" == "linux" ]]
then
  wget http://codesynthesis.com/download/odb/2.4/odb-2.4.0-x86_64-linux-gnu.tar.bz2 -O /tmp/odb.tar.bz2
  tar jxf /tmp/odb.tar.bz2
elif [[ "$OS_NAME" == "osx" ]]
then
  wget http://codesynthesis.com/download/odb/2.4/odb-2.4.0-i686-macosx.tar.bz2 -O /tmp/odb.tar.bz2
  tar jxf /tmp/odb.tar.bz2
else
  echo "Invalid OS name"
  echo "$help_install_dependencies"
  exit
fi

cd ..

echo "Dependencies folder:"
ls $dependencies_dir

if [ $INSTALL_FAILED -gt 0 ]
then
  echo "ERROR: Automatic installation failed, see above logs."
else
  echo "Automatic installation completed successfully."
fi
