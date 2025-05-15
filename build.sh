#!/bin/bash

# Exit on any error
set -e

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

# Navigate to build directory
cd build

# Configure the project with CMake, generating compile_commands.json
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Build the project
make

# Run the tests
./tests --rng-seed 0
