cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0 LANGUAGES CXX)

include_directories(include)

add_library(mylib STATIC src/mylib.cpp)

# Build test code together with building production code
add_subdirectory(test)

# Enable testing in this directory or below
enable_testing()