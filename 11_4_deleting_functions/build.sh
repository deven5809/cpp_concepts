#!/bin/bash

# Check to see if the build directory exists and enter it.
if [ ! -d "out" ]; then
    mkdir out
fi
cd out

# Build the program
g++ -o main ./../main.cpp -g