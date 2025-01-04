cmake_minimum_required(VERSION 3.14)

set(this myprogram)
project(${this})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    turtle.cpp
    turtle_activity.cpp
)

add_executable(
    ${this}
    ${SOURCES}
)
