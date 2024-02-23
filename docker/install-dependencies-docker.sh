#!/bin/bash
#
# NOTE: this is a modified version of install-dependencies.sh, where we strip out the things we
# either install via apt (i.e., libz, libbz2, libboost) or build via build2 (i.e., odb).
#

# stop the script if any command fails
set -e

# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'if [ $? -ne 0 ]; then echo "******ERROR******: \"${last_command}\" command failed with exit code $?." && echo "Installation of dependencies failed!"; fi' EXIT

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
  - openssl library                         openssl-1.1.1f
  - c-ares library                          c-ares-1.15.0
  - boost library                           boost-1.72.0
  - nghttp2 library (osx only)              nghttp2-1.47.0
  - brotli library (osx only)               brotli-1.0.9

for linux:
./install_dependencies.sh linux

for mac os:
./install_dependencies.sh osx
"


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

# Download ODB runtime library, sqlite DB plugin for ODB, libbz2 and libz.
echo "creating directory $dependencies_dir"
mkdir -p $dependencies_dir && cd $dependencies_dir

dependencies_dir_abs_path=`pwd`

echo "installing openssl"
mkdir openssl
wget https://www.openssl.org/source/openssl-1.1.1f.tar.gz -O ./openssl-1.1.1f.tar.gz
tar xzf ./openssl-1.1.1f.tar.gz
cd openssl-1.1.1f
LIBS="-lcrypto -ldl" \
./config -fPIC no-shared no-threads \
        --prefix=$dependencies_dir_abs_path/openssl \
        --openssldir=$dependencies_dir_abs_path/openssl
make && make install_sw
cd ..

echo "installing c-ares"
mkdir c-ares
wget https://c-ares.haxx.se/download/c-ares-1.15.0.tar.gz -O ./c-ares-1.15.0.tar.gz
tar xzf ./c-ares-1.15.0.tar.gz
cd c-ares-1.15.0
./configure --prefix=$dependencies_dir_abs_path/c-ares
make && make install
cd ..

echo "installing libcurl"
mkdir curl
wget https://curl.haxx.se/download/curl-7.62.0.tar.gz -O ./curl-7.62.0.tar.gz
tar zxf ./curl-7.62.0.tar.gz
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
