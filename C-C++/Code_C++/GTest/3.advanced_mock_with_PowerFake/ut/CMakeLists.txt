cmake_minimum_required(VERSION 3.14)

set(this turtle_activity_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Clone gtest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

# Clone powerfake
# include(FetchContent)
# FetchContent_Declare(
#     powerfake
#     URL https://github.com/hedayat/powerfake/archive/refs/heads/master.zip
# )

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Configure to build the code
enable_testing()

# Configure for code-under-test. Build it to a library
set(SOURCES
    ../src/turtle_activity.cpp
)
add_library(turtle_activity STATIC
    ${SOURCES}
)

# Configure for unit code. Build it to an execuable that uses the CUT library
add_executable(${this}
    turtle_activity_test.cpp
)
target_link_libraries(${this} PUBLIC
    GTest::gtest_main
    GTest::gmock_main
    turtle_activity
)
include_directories(
    ../src
)
