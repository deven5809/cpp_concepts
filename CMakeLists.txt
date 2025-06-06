# The minimum required version of CMake to build this project.
cmake_minimum_required(VERSION 3.16)

project(cpp_concepts
    VERSION 1.0
    LANGUAGES CXX)

# Add CXX version/standard here. We'll be using C++ 23.
set(CMAKE_CXX_STANDARD 23)

# Build Arguments
# cmake -DMY_VARIABLE:STRING=option_value2
SET(BUILD_VARIANT "all" CACHE STRING "Defines which examples to build")

# Define all possible/supported builds.
set(SUPPORTED_VARIANTS
    "11_2"
    "11_4"
    "11_5"
)

# Check to see if the variant specified is in the list
add_subdirectory(11_2_function_overload_differentiation)
add_subdirectory(11_4_deleting_functions)
add_subdirectory(11_5_default_arguments)