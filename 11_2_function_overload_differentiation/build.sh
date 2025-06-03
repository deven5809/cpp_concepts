#!/bin/bash

if [ ! -d "out" ]; then
    mkdir out
fi

cd out

# Build the program
g++ -o main ./../main.cpp -g