#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to build directory
cd build

# Run CMake if CMakeCache.txt doesn't exist
if [ ! -f CMakeCache.txt ]; then
    cmake ..
fi

# Build the project
cmake --build .

# Run the main executable
./main
