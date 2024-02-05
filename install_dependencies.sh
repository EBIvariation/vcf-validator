#!/bin/bash

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
  - bzip library (linux only)               bzip2-1.0.6
  - zlib library (linux only)               zlib-1.2.11
  - curl library (linux only)               curl-7.62.0
  - openssl library (linux only)            openssl-1.1.1w
  - c-ares library (linux only)             c-ares-1.15.0
  - boost library (linux only)              boost-1.72.0

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

#check for already downloaded files
if [ "$(ls -A $dependencies_dir)" ]; then
  echo "ERROR: Found non-empty directory of a previous installation: \"$dependencies_dir\". Please remove the folder before running this script. Current contents:"
  ls $dependencies_dir
  exit 0
fi


# Download ODB runtime library, sqlite DB plugin for ODB, libbz2 and libz.
echo "creating directory $dependencies_dir"
mkdir -p $dependencies_dir && cd $dependencies_dir

echo "installing libodb"
wget http://codesynthesis.com/download/odb/2.4/libodb-2.4.0.tar.bz2 -O ./libodb.tar.bz2
tar jxf ./libodb.tar.bz2
cd libodb-2.4.0
if [[ "$OS_NAME" == "osx" ]]
then
  #change name of file to avoid build issues in mac
  mv version version_odb
  sed 's/^dist_doc_DATA = GPLv2 LICENSE README NEWS version$/dist_doc_DATA = GPLv2 LICENSE README NEWS version_odb/' Makefile.am > Makefile.tmp
  mv Makefile.tmp Makefile.am
  ./bootstrap
fi
./configure && make
cd ..

echo "installing libodb-sqlite"
wget http://codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.tar.bz2 -O ./libodb-sqlite.tar.bz2
tar jxf ./libodb-sqlite.tar.bz2
cd libodb-sqlite-2.4.0
if [[ "$OS_NAME" == "osx" ]]
then
  #change name of file to avoid build issues in mac
  mv version version_sqlite
  sed 's/^dist_doc_DATA = GPLv2 LICENSE README NEWS version$/dist_doc_DATA = GPLv2 LICENSE README NEWS version_sqlite/' Makefile.am > Makefile.tmp
  mv Makefile.tmp Makefile.am
  ./bootstrap
fi
./configure --with-libodb=../libodb-2.4.0 && make
cd ..

if [[ "$OS_NAME" != "osx" ]]
then
  #linux 
  echo "installing libbz2"
  # This is commented till the bzip.org site is recovered.
  # wget http://www.bzip.org/1.0.6/bzip2-1.0.6.tar.gz -O ./libbz2.tar.gz
  # tar zxf ./libbz2.tar.gz
  # Till then we can trust ubuntu archives.
  wget http://archive.ubuntu.com/ubuntu/pool/main/b/bzip2/bzip2_1.0.6.orig.tar.bz2 -O ./libbz2.tar.bz2
  tar jxf ./libbz2.tar.bz2
  cd bzip2-1.0.6 && make
  cd ..

  echo "installing libz"
  wget http://prdownloads.sourceforge.net/libpng/zlib-1.2.11.tar.gz?download -O ./libz.tar.gz
  tar zxf ./libz.tar.gz
  cd zlib-1.2.11 && cmake . && make
  cd ..

  dependencies_dir_abs_path=`pwd`

  echo "installing openssl"
  mkdir openssl
  #using latest openssl which supports mac arm as well
  wget https://www.openssl.org/source/openssl-1.1.1w.tar.gz -O ./openssl-1.1.1w.tar.gz
  tar xzf ./openssl-1.1.1w.tar.gz
  cd openssl-1.1.1w
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
  cd ..

  echo "installing  boost"
  wget https://boostorg.jfrog.io/artifactory/main/release/1.72.0/source/boost_1_72_0.tar.gz -O ./boost.tar.gz
  tar zxf ./boost.tar.gz
  mv boost_1_72_0 boost && cd boost

  # If there's some error like "undefined reference to bzip2_base", then boost didn't compile everything for iostreams.
  # The boost iostreams compilation was ok if this command finds some lines "nm libboost_iostreams.a | grep bzip2_base".
  # The next user-config.jam should fix that.
  # Documentation on building iostreams: https://www.boost.org/doc/libs/1_72_0/libs/iostreams/doc/index.html
  # Documentation on specifying zlib and bzip2: https://boostorg.github.io/build/manual/master/index.html#bbv2.reference.tools.libraries.zlib
  echo "
using zlib : 1.2.11 : <include>${dependencies_dir_abs_path}/zlib-1.2.11 <search>${dependencies_dir_abs_path}/ ;
using bzip2 : 1.0.6 : <include>${dependencies_dir_abs_path}/bzip2-1.0.6 <search>${dependencies_dir_abs_path}/ ;
" > tools/build/src/user-config.jam

  ./bootstrap.sh --with-libraries=filesystem,iostreams,log,program_options,regex && ./b2 link=static
  cd ..
fi


# Make easier to find the static libraries
cp libodb-2.4.0/odb/.libs/libodb.a .
cp libodb-sqlite-2.4.0/odb/sqlite/.libs/libodb-sqlite.a .

if [[ "$OS_NAME" != "osx" ]]
then
  #linux
  cp bzip2-1.0.6/libbz2.a .
  cp zlib-1.2.11/libz.a .
fi

# copy headers
cp -r libodb-2.4.0/odb ./
cp -r libodb-sqlite-2.4.0/odb/sqlite ./odb/

# Download odb compiler
if [[ "$OS_NAME" == "linux" ]]
then
  wget http://codesynthesis.com/download/odb/2.4/odb-2.4.0-x86_64-linux-gnu.tar.bz2 -O ./odb.tar.bz2
  tar jxf ./odb.tar.bz2
elif [[ "$OS_NAME" == "osx" ]]
then
  wget http://codesynthesis.com/download/odb/2.4/odb-2.4.0-i686-macosx.tar.bz2 -O ./odb.tar.bz2
  tar jxf ./odb.tar.bz2
else
  echo "Invalid OS name"
  echo "$help_install_dependencies"
  exit
fi

cd ..

echo "Dependencies folder:"
ls $dependencies_dir

echo -e "\nAutomatic installation completed successfully."
