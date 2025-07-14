#!/bin/bash

set -e

rm -rf dependencies
./install_dependencies.sh

rm -rf build
mkdir build
cd build

cmake -DSTATIC_BUILD=ON ..
make -j$(nproc)

cd ..

build/bin/test_validation_suite

rm -rf dependencies
