cmake_minimum_required(VERSION 3.14)
project(my_project)                         # Set your project name

# Specify compiler version, etc.
set(CMAKE_CXX_STANDARD 14)                  # GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Clone gtest from github
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip       # Should change the commit hash (or tag) to the latest gtest version
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Configure to build the code
enable_testing()

add_executable(
  hello_test                            # Set name for the test executable
  hello_test.cc                         # Set path to the test code
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)
