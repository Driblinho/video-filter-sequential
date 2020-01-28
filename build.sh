#!/bin/bash
cmake -S . -B cmake-build-debug
cd cmake-build-debug
cmake ..
make -j4