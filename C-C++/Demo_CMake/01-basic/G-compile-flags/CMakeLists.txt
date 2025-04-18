cmake_minimum_required(VERSION 3.5)

# Set a default C++ compile flag. SHOULD NOT USE!
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX1" CACHE STRING "Set C++ Compiler Flags" FORCE)

# Set the project name
project(compile_flags)

# Add an executable
add_executable(cmake_examples_compile_flags main.cpp)

target_compile_definitions(cmake_examples_compile_flags 
    PRIVATE EX2
)

message("1 ${PROJECT_SOURCE_DIR}")
message("2 ${CMAKE_CURRENT_BINARY_DIR}")
