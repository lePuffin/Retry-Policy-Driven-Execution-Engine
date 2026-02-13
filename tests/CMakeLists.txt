# Set the minimum version of CMake required for this project
cmake_minimum_required(VERSION 3.28)

# Set the project name and version
project(UnitTests VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# CppUTest setup
if(NOT DEFINED ENV{CPPUTEST_HOME})
    message(FATAL_ERROR "The environment variable CPPUTEST_HOME is not set. Set it to where cpputest is installed")
endif()

set(CPPUTEST_HOME $ENV{CPPUTEST_HOME})


# Gather all source files from the tests directory
file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Create an executable for tests
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}        # tests dir
    ${CMAKE_SOURCE_DIR}/src            # main project headers
    ${CPPUTEST_HOME}/include           # CppUTest headers
)

# Enable exception handling during compilation
target_compile_options(${PROJECT_NAME} PRIVATE -fexceptions)

# Link the implementation library
target_link_libraries(${PROJECT_NAME} PRIVATE source_library)

# Link the CppUTest library to the tests executable
# target_include_directories(${PROJECT_NAME} PUBLIC ${CPPUTEST_HOME}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CPPUTEST_HOME}/build/src/CppUTest/libCppUTest.a
    ${CPPUTEST_HOME}/build/src/CppUTestExt/libCppUTestExt.a
)

# Link the platform threads library (pthread) so CppUTest platform code links correctly
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# Link with C++ standard library explicitly
# target_link_libraries(${PROJECT_NAME} PRIVATE stdc++)