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

dependencies_dir="dependencies"


#check for already downloaded files
if [ "$(ls -A $dependencies_dir)" ]; then
  echo "ERROR: Found non-empty directory of a previous installation: \"$dependencies_dir\". Please remove the folder before running this script. Current contents:"
  ls $dependencies_dir
  exit 1
fi


echo "creating directory $dependencies_dir"
mkdir -p $dependencies_dir && cd $dependencies_dir

dependencies_dir_abs_path=`pwd`
build_dir_abs_path=${dependencies_dir_abs_path}/build
mkdir $build_dir_abs_path

if [[ "$OS_NAME" != "osx" ]]
then
  #linux

  # Download libbz2 and libz.
  echo "installing libbz2"
  wget http://archive.ubuntu.com/ubuntu/pool/main/b/bzip2/bzip2_1.0.6.orig.tar.bz2 -O ./libbz2.tar.bz2
  tar jxf ./libbz2.tar.bz2
  cd bzip2-1.0.6 && make && make install PREFIX=$build_dir_abs_path
  cd ..

  echo "installing libz"
  wget http://prdownloads.sourceforge.net/libpng/zlib-1.2.11.tar.gz?download -O ./libz.tar.gz
  tar zxf ./libz.tar.gz
  cd zlib-1.2.11 && ./configure --prefix=$build_dir_abs_path && make install
  cd ..

  echo "installing openssl"
  #using openssl v1.1.1w which supports mac arm as well
  wget https://www.openssl.org/source/openssl-1.1.1w.tar.gz -O ./openssl-1.1.1w.tar.gz
  tar xzf ./openssl-1.1.1w.tar.gz
  cd openssl-1.1.1w
  LIBS="-lcrypto -ldl" \
  ./config -static --static -fPIC no-shared no-threads \
          --prefix=$build_dir_abs_path \
          --openssldir=$build_dir_abs_path
  make && make install_sw
  cd ..

  echo "installing c-ares"
  wget https://github.com/c-ares/c-ares/releases/download/cares-1_15_0/c-ares-1.15.0.tar.gz -O ./c-ares-1.15.0.tar.gz
  tar xzf ./c-ares-1.15.0.tar.gz
  cd c-ares-1.15.0
  ./configure --prefix=$build_dir_abs_path
  make && make install
  cd ..

  echo "installing libcurl"
  wget https://curl.haxx.se/download/curl-7.62.0.tar.gz -O ./curl-7.62.0.tar.gz
  tar zxf ./curl-7.62.0.tar.gz
  cd curl-7.62.0
  LDFLAGS="-L$build_dir_abs_path/lib" \
  CPPFLAGS="-I$build_dir_abs_path/include" \
  ./configure --disable-shared \
              --enable-static \
              --without-librtmp \
              --without-ca-bundle \
              --disable-ldap \
              --without-zlib \
              --without-libidn2 \
              --without-nss \
              --enable-ares=$build_dir_abs_path \
              --with-ssl=$build_dir_abs_path \
              --prefix=$build_dir_abs_path
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
#  echo "
#using zlib : 1.2.11 : <include>${build_dir_abs_path}/zlib-1.2.11 <search>${build_dir_abs_path}/ ;
#using bzip2 : 1.0.6 : <include>${build_dir_abs_path}/bzip2-1.0.6 <search>${build_dir_abs_path}/ ;
#" > tools/build/src/user-config.jam
  echo "
using zlib : 1.2.11 : <source>${dependencies_dir_abs_path}/zlib-1.2.11 ;
using bzip2 : 1.0.6 : <source>${dependencies_dir_abs_path}/bzip2-1.0.6 ;
" > tools/build/src/user-config.jam

  ./bootstrap.sh --prefix=${build_dir_abs_path}  --with-libraries=filesystem,iostreams,log,program_options,regex,system && ./b2 link=static --prefix=${build_dir_abs_path} install
  cd ..
fi

cd ..

echo "Dependencies folder:"
ls $build_dir_abs_path

echo -e "\nAutomatic installation completed successfully."
