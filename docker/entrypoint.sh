#!/bin/bash

NPROCS=`grep processor </proc/cpuinfo | wc -l`

mkdir -p /tmp/build
cd /tmp/build
cmake -DBUILD_STATIC=1 ..
make -j${NPROCS}
