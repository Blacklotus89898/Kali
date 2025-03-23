cmake_minimum_required(VERSION 3.10)
project(myProjectName)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(myProjectName src/main.cpp src/myClass1.cpp)
