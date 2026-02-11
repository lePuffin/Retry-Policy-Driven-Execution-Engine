cmake_minimum_required(VERSION 3.28)

project(PolicyDrivenExecutionEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Gather all source files from the tests directory
file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Create a library with implementation files
add_library(source_library
    ${SOURCE_FILES}
)
target_include_directories(source_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Main application executable
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE source_library)
