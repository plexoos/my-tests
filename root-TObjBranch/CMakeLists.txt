cmake_minimum_required( VERSION 3.2 FATAL_ERROR )

project( root-TObjBranch )


# Add to path in order to pick up the FindXXX.cmake files included in this project
list( APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake" )

# This project depends on ROOT
find_package( ROOT )

set(CMAKE_CXX_STANDARD 11)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${ROOT_INCLUDE_DIR}
)


root_generate_dictionary(
	muDstProjectDict
	muDst/muDstProjectHeaders.h
	LINKDEF muDst/muDstLinkDef.h
)

add_executable( test-TObjBranch
	main.cxx
	muDst/muDstProjectSource.cxx
	muDstProjectDict.cxx
)

target_link_libraries(test-TObjBranch ${ROOT_LIBRARIES})
