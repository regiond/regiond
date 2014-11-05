cmake_minimum_required (VERSION 3.0)
project (regiond)

set(regiond_VERSION_MAJOR 0)
set(regiond_VERSION_MINOR 0)
set(regiond_VERSION_PATCH 0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)

# Automatically build documentation, if Doxygen is installed
find_package(Doxygen)
if(DOXYGEN_FOUND)
	set(NULLPIPE ">/dev/null")
	if(WIN32)
		set(NULLPIPE ">NUL")
	endif()
	
	add_custom_target(docs ALL
		${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile > /dev/null
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		VERBATIM
	)
else()
	warning("Doxygen wasn't found; can't build documentation!")
endif()
