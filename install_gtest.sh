#!/bin/bash

INIT_DIR=$(pwd)

apt-get install libgtest-dev cmake build-essential -y
cd /usr/src/googletest/
mkdir -p build
cd build
cmake ..
make
make install

cd $INIT_DIR
