cmake_minimum_required(VERSION 3.10)
project(Calculator LANGUAGES CXX)

# Declare the executable for the project
add_executable(project_main main.cpp math.cpp)

# Include the "include" directory for header files
target_include_directories(project_main PRIVATE ../include)