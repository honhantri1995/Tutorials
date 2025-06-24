# Add the test executable
add_executable(test_mylib test_mylib.cpp)

# Link the library with the test
target_link_libraries(test_mylib PRIVATE mylib)

# Define a test
add_test(NAME MyLibTest COMMAND test_mylib)