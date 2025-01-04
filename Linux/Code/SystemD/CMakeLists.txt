cmake_minimum_required(VERSION 3.10)
project(MyService)

set(CMAKE_CXX_STANDARD 11)

# Add the executable
add_executable(myservice
    main.cpp
)

# Link against systemd
target_link_libraries(myservice
    systemd
)