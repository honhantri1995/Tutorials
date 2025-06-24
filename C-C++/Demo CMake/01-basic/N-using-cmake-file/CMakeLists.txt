cmake_minimum_required(VERSION 3.10)
project(SimpleCalculator)

# Add option for verbose output
# Note that options will be added to CMakeCache.txt,
#  so you'll need to "rm CMakeCache.txt" before "cmake .." to switch between ON/OFF value.
option(ENABLE_VERBOSE "Enable verbose output during build" ON)

# Include the common file
include(cmake/common.cmake)

# Then you can call functions from common.cmake
# If you move these function calls to above the include(), you'll get error "Unknown CMake command xxx."
set_common_flags()
add_common_includes()
enable_verbose()

# Create a library for the calculator
add_library(calculator src/calculator.cpp)

# Create an executable
add_executable(SimpleCalculator src/main.cpp)

# Link the calculator library to the executable
target_link_libraries(SimpleCalculator PRIVATE calculator)