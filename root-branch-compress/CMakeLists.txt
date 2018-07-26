cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(root-branch-compress)

set(CMAKE_CXX_STANDARD 11)

# Add to path in order to pick up the FindXXX.cmake files included in this project
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

# This project depends on ROOT
find_package(ROOT)

if( ${ROOT_CXX_FLAGS} MATCHES "-m32" )
	message(STATUS "Found -m32 option in $ROOT_CXX_FLAGS (root-config). Will add it to $CMAKE_CXX_FLAGS")
	set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS FALSE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
endif()

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${ROOT_INCLUDE_DIR}
)


root_generate_dictionary(
	DemoDouble32_dict
	DemoDouble32.h
	LINKDEF LinkDef.h
)

add_executable(compress compress.cpp DemoDouble32_dict.cxx)
target_link_libraries(compress ${ROOT_LIBRARIES})
