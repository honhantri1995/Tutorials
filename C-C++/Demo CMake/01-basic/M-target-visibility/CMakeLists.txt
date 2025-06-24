cmake_minimum_required(VERSION 3.10)
project(MyApp)

###################################### PUBLIC ######################################
######## Lib #########
# Create a static library
add_library(util STATIC src/util.cpp)

# Specify include directories for the library
target_include_directories(util PUBLIC include)

######## Exe #########
# Create an executable that uses the library
add_executable(MyApp src/main.cpp)

# Link the library to the executable
target_link_libraries(MyApp PRIVATE util)


###################################### PRIVATE ######################################
######## Lib #########
# # Create a static library
# add_library(util STATIC src/util.cpp)

# # Specify include directories for the library
# target_include_directories(util PRIVATE include)

# ######## Exe #########
# # Create an executable that uses the library
# add_executable(MyApp src/main.cpp)

# # Link the library to the executable
# target_link_libraries(MyApp PRIVATE util)

# # Specify include directories for the executable
# target_include_directories(MyApp PRIVATE include)


###################################### INTERFACE ######################################
# # ######## Lib #########
# # Create a header-only library target
# add_library(util INTERFACE)

# # Specify include directories for the header-only library
# target_include_directories(util INTERFACE include)

# # ######## Exe #########
# # Create an executable that uses the library
# add_executable(MyApp src/main.cpp)

# # Link the library to the executable
# target_link_libraries(MyApp PRIVATE util)