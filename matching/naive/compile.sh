#!/bin/bash

# finish the compilation
if [ -d "./build" ] 
then
    rm -rf build 
fi
mkdir build

# for checking the performance
cd build && cmake .. 

# for checking the matched patterns 
# cd build && cmake -DACTION ..
make

echo "Executables are generated!"
echo
echo
