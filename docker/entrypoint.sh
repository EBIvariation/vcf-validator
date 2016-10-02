#!/bin/bash

NPROCS=`grep processor </proc/cpuinfo | wc -l`

# Generate last version of parser sources from Ragel descriptors
cd /tmp
for i in 1 2 3 ; do ragel -G2 -o inc/vcf/validator_detail_v4${i}.hpp src/vcf/vcf_v4${i}.ragel ; done

# Create build directory
mkdir -p /tmp/build
cd /tmp/build

# Build a static binary
cmake -DBUILD_STATIC=1 ..
make -j${NPROCS}

