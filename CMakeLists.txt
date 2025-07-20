cmake_minimum_required(VERSION 3.16)

project(incarnating-radius
        VERSION 2025.7.12
        DESCRIPTION "soft real-time agent-based computer simulation engine"
        LANGUAGES CXX)

# TODO Setup file that detects system variables and details?

# TODO Add definitions for build type to pass down to C++ code

add_subdirectory(preproc)
add_subdirectory(memalloc)
