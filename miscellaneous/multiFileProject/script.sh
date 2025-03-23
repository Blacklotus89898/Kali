#!/bin/bash

# Set script to exit on any error
set -e

# Build the project
echo "Building the project..."
make

# Run tests
echo "Running tests..."
make tests
./runTests

# Clean the project
echo "Cleaning the project..."
make clean

echo "Build, test, and clean process completed successfully!"
