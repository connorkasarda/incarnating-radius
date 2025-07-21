cmake_minimum_required(VERSION 3.16)

project(incarnating-radius
        VERSION 2025.7.20
        DESCRIPTION "soft real-time agent-based computer simulation engine"
        LANGUAGES CXX)

# TODO Setup file that detects system variables and details?

# Add compiler definitions for build type to pass down to source code
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_BUILD)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DRELEASE_BUILD)
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    add_definitions(-DRELWITHDEBINFO_BUILD)
elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    add_definitions(-DMINSIZEREL_BUILD)
else()
    message(FATAL_ERROR "Unknown build type: `${CMAKE_BUILD_TYPE}`")
endif()

add_subdirectory(preproc)
add_subdirectory(memalloc)
