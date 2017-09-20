cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(my-tests)


# Check whether the compiler supports c++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
	message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()



# Add to path in order to pick up the FindXXX.cmake files included in this project
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# This project depends on ROOT
find_package(ROOT)

if(NOT ROOT_FOUND)
   message(FATAL_ERROR "Fatal error: ROOT package not found")
endif()


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

add_executable(test-StiTrackNode-errPropag6 test-StiTrackNode-errPropag6/main.cxx)
target_link_libraries(test-StiTrackNode-errPropag6 rt pthread)

add_executable(test-StiTrackNode-errPropag6-vs-trasat-output test-StiTrackNode-errPropag6/main-errPropag6-vs-trasat-output.cxx)


root_generate_dictionary (
   Sti_dict
   test-StiTrackNodeHelper-joinTwo/FuncArgsJoinTwo.h
   LINKDEF test-StiTrackNodeHelper-joinTwo/LinkDef.h
)

add_executable(test-StiTrackNodeHelper-joinTwo test-StiTrackNodeHelper-joinTwo/main.cxx Sti_dict.cxx)
target_link_libraries(test-StiTrackNodeHelper-joinTwo ${ROOT_LIBRARIES} rt pthread)
