cmake_minimum_required(VERSION 3.5)

# Set the project name
project(third_party_include)

# Find a boost install with the libraries filesystem and system
find_package(Boost 1.46.1
    REQUIRED
    COMPONENTS filesystem system
)

# Check if boost was found
# Boost_FOUND is defined in FindBoost.cmake.
if(Boost_FOUND)
    message("boost found")

    # Add an executable
    add_executable(third_party_include main.cpp)
    
    # Link against the boost libraries
    target_link_libraries(third_party_include
    PRIVATE
    Boost::filesystem
    )
else()
    message(FATAL_ERROR "Cannot find Boost")
endif()
