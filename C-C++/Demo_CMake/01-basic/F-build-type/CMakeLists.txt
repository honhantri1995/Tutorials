cmake_minimum_required(VERSION 3.10)
project(MyProject)
add_executable(myexe main.cpp)

# Set the build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
message("Build type: ${CMAKE_BUILD_TYPE}")

# Set compiler flags and options based on the build type
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(myexe PRIVATE DEBUG_MODE)
    target_compile_options(myexe PRIVATE -g)  # Enable debug symbols
else()
  target_compile_definitions(myexe PRIVATE NODEBUG_MODE)
  target_compile_options(myexe PRIVATE -Os)
endif()

# Print the compiler flags
get_target_property(FLAGS myexe COMPILE_DEFINITIONS)
foreach(option ${FLAGS})
    message("Compiler flag: ${option}")
endforeach()

# Print the compiler options
get_target_property(OPTS myexe COMPILE_OPTIONS)
foreach(option ${OPTS})
    message("Compiler option: ${option}")
endforeach()

# Create a custom CMake target to run your executable directly from the build system.
# The benefit is that you don't need to locate your executable.
add_custom_target(run
    COMMAND myexe
    DEPENDS myexe
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)