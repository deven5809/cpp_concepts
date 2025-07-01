# The minimum required version of CMake to build this project.
cmake_minimum_required(VERSION 3.16)

project(cpp_concepts
    VERSION 1.0
    LANGUAGES CXX)

# Build Arguments
# cmake -DBUILD_VARIANT:STRING=all
SET(BUILD_VARIANT "11_2" CACHE STRING "Defines which examples to build")

# Define all possible/supported builds.
set(SUPPORTED_VARIANTS
    "11_2"
    "11_4"
    "11_5"
)

if (BUILD_VARIANT IN_LIST SUPPORTED_VARIANTS)
    # Check to see if the variant specified is in the list
    add_subdirectory(11_2_function_overload_differentiation)
    add_subdirectory(11_4_deleting_functions)
    add_subdirectory(11_5_default_arguments)
    add_subdirectory(11_9_non_type_template_parameters)
endif()
