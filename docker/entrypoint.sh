#!/bin/bash

# NPROCS=`grep processor </proc/cpuinfo | wc -l`

mkdir -p /tmp/build
cd /tmp/build
cmake -DBUILD_STATIC=1 -DODB_PATH=/usr/lib/x86_64-linux-gnu/ ..
# make -j${NPROCS}
make
