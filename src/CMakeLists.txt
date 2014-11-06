# Locate and include Boost; we only want static libs though
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.56.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Find all sources
file(GLOB_RECURSE regiond_SOURCES *.cpp)

# Build and link the regiond executable
add_executable(regiond ${regiond_SOURCES})
target_link_libraries(regiond ${Boost_LIBRARIES})
