#!/bin/bash

set -e

rm -rf build
mkdir build
cd build

cmake -DSTATIC_BUILD=OFF ..
make -j$(nproc)
cd ..
build/bin/test_validation_suite

