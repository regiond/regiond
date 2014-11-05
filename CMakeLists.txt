cmake_minimum_required (VERSION 3.0)
project (regiond)

set(regiond_VERSION_MAJOR 0)
set(regiond_VERSION_MINOR 0)
set(regiond_VERSION_PATCH 0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
