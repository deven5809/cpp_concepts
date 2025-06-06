#!/bin/bash

# Check to see if the build directory exists and enter it.
if [ ! -d "out" ]; then
    mkdir out
fi
cd out

# Run CMake to generate a build system.
cmake ../

# Perform the build.
cmake --build .