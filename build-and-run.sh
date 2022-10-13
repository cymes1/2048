#!/bin/bash

# creating directory build if not exist
mkdir -p build
cd build || exit

# running cmake
if ! cmake ..; then
  exit 1
fi

# running make
if ! make; then
  exit 1
fi

# running program
cd build/bin || exit
./2048 --verbose

# returning to root directory
cd ..
