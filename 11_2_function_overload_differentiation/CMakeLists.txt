# The minimum required version of CMake to build this project.
cmake_minimum_required(VERSION 3.16)

project(11_2_function_overload_differentiation
    VERSION 1.0
    LANGUAGES CXX)

# Add CXX version/standard here. We'll be using C++ 20. The 
# CMAKE_CXX_STANDARD_REQUIRED boolean sets CXX_STANDARD_REQUIRED
# to make sure that the CXX_STANDARD is not allowed to decay to 
# lower version.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the executable name and target name.
set(EXECUTABLE_NAME ${PROJECT_NAME})
set(EXECUTABLE_TARGET ${EXECUTABLE_NAME}_exe)

# Add source files here
add_library(${PROJECT_NAME}
    main.cpp
    OverloadClass.hpp
)

add_executable(${EXECUTABLE_TARGET}
    main.cpp
)

# This is a custom build command to move the executable to a common location
# after the build is completed for conveniences sake.
add_custom_command(TARGET ${EXECUTABLE_TARGET} POST_BUILD
    # Create a folder specifically for the executable and move it there. 
    COMMAND mkdir -p ${PROJECT_BINARY_DIR}/../executables/
    COMMAND cp ${PROJECT_BINARY_DIR}/${EXECUTABLE_TARGET} ${PROJECT_BINARY_DIR}/../executables/
)