cmake_minimum_required(VERSION 3.10)
project(ML_Library_From_Scratch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include all our custom headers
include_directories(include)

# Gather all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Build the core library
add_library(ml_core ${SOURCES})

# Build the example executable
add_executable(run_ml examples/main.cpp)
target_link_libraries(run_ml ml_core)
