# The minimum required version of CMake to build this project.
cmake_minimum_required(VERSION 3.16)

project(11_5_default_arguments
    VERSION 1.0
    LANGUAGES CXX)

# Add CXX version/standard here. We'll be using C++ 20. The 
# CMAKE_CXX_STANDARD_REQUIRED boolean sets CXX_STANDARD_REQUIRED
# to make sure that the CXX_STANDARD is not allowed to decay to 
# lower version.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files here
add_library(${PROJECT_NAME}
    main.cpp
)

add_executable(default_arguments
    main.cpp
)