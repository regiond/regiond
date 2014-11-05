cmake_minimum_required (VERSION 2.8)
project (regiond)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (regiond_VERSION_MAJOR 0)
set (regiond_VERSION_MINOR 0)
set (regiond_VERSION_PATCH 0)

configure_file ("${PROJECT_SOURCE_DIR}/src/config.h.in" "${PROJECT_BINARY_DIR}/config.h")
include_directories ("${PROJECT_BINARY_DIR}")

file (GLOB_RECURSE regiond_SOURCES src true src/*.cpp src/*.h)
add_executable (regiond ${regiond_SOURCES})
install (TARGETS regiond DESTINATION bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
include_directories ("/usr/local/include")

add_definitions (-DASIO_STANDALONE)
include_directories ("${PROJECT_SOURCE_DIR}/lib/asio/asio/include")

find_library (POCO_FOUNDATION PocoFoundation)
find_library (POCO_UTIL PocoUtil)
find_library (POCO_JSON PocoJSON)
target_link_libraries(regiond ${POCO_FOUNDATION} ${POCO_UTIL} ${POCO_JSON})



source_group ("Application" "Application/.*")
source_group ("Providers/Tor" "Providers/Tor/.*")
source_group ("Proxy Server" "ProxyServer/.*")
source_group ("Common" "Common/.*")
