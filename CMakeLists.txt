cmake_minimum_required(VERSION 3.10)

project(Compilator)

# Add the sources for your project (e.g., lexer.cpp, main.cpp, etc.)
set(SOURCES
    src/lexer/lexer.cpp
    # Add more source files here as needed
)

# Define the executable for your compiler
add_executable(compilator ${SOURCES})

# Include directories for your project
target_include_directories(compilator PRIVATE src)

# Add a test executable for running unit tests
add_executable(tests
    tests/lexer/lexer_tests.cpp
    src/lexer/lexer.cpp
    # Add more test files for other components as needed
)

# Include Google Test library
find_package(GTest REQUIRED)
target_include_directories(tests PRIVATE ${GTEST_INCLUDE_DIRS})

# Link the test executable with your project and Google Test
target_link_libraries(tests PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)

# Add a custom target for running tests with 'make test'
add_custom_target(run_tests COMMAND tests)
