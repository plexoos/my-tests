cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(my-tests)

set( CMAKE_CXX_STANDARD 11 )

# Add to path in order to pick up the FindXXX.cmake files included in this project
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# This project depends on ROOT
find_package(ROOT)


include_directories(
	${ROOT_INCLUDE_DIR}
	${EIGEN_INCLUDE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
)

link_directories( ${ROOT_LIBRARY_DIR} )


add_executable(float_vs_double misc/float_vs_double.cxx)
target_link_libraries(float_vs_double rt pthread)

add_executable(std_function misc/std_function.cxx)
add_executable(std_chrono misc/std_chrono.cxx)
add_executable(matrix_pack_unpack misc/matrix_pack_unpack.cxx)

add_subdirectory(linux)

add_executable(test-StiTrackNode-errPropag6 test-StiTrackNode-errPropag6/main.cxx)
target_link_libraries(test-StiTrackNode-errPropag6 rt pthread)

add_executable(test-StiTrackNode-errPropag6-vs-trasat-output test-StiTrackNode-errPropag6/main-errPropag6-vs-trasat-output.cxx)


root_generate_dictionary(
	Sti_dict
	test-StiTrackNodeHelper-joinTwo/FuncArgsJoinTwo.h
	LINKDEF test-StiTrackNodeHelper-joinTwo/LinkDef.h
)

add_executable(test-StiTrackNodeHelper-joinTwo test-StiTrackNodeHelper-joinTwo/main.cxx Sti_dict.cxx)
target_link_libraries(test-StiTrackNodeHelper-joinTwo ${ROOT_LIBRARIES} rt pthread)
