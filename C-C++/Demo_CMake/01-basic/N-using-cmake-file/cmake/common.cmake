# Function to add common compiler flags
function(set_common_flags)
    message(STATUS "Setting common compiler flags...")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endfunction()

# Function to set include directories
function(add_common_includes)
    include_directories(include)
    message(STATUS "Included directories: include")
endfunction()

# Function to enable verbose output if required
function(enable_verbose)
    if(ENABLE_VERBOSE)
        message(STATUS "Verbose output is enabled.")
        set(CMAKE_VERBOSE_MAKEFILE ON)
    else()
        message(STATUS "Verbose output is disabled.")
    endif()
endfunction()