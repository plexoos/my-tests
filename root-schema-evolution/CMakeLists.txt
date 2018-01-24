cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(root-schema-evolution)

# Add to path in order to pick up the FindXXX.cmake files included in this project
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

# This project depends on ROOT
find_package( ROOT )

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${ROOT_INCLUDE_DIR}
)


root_generate_dictionary(
	MyClassA_8_dict
	MyClassA_8.h
	LINKDEF MyClassA_8_LinkDef.h
)

add_executable(write_A8 write_A8.cxx MyClassA_8_dict.cxx)
target_link_libraries(write_A8 ${ROOT_LIBRARIES} pthread)


root_generate_dictionary(
	MyClassA_9_dict
	MyClassA_9.h
	LINKDEF MyClassA_9_LinkDef.h
)

add_executable(read_A8_via_A9 read_A8_via_A9.cxx MyClassA_9_dict.cxx)
target_link_libraries(read_A8_via_A9 ${ROOT_LIBRARIES} pthread)


root_generate_dictionary(
	MyClassB_3_dict
	MyClassA_9.h
	MyClassB_3.h
	LINKDEF MyClassB_3_LinkDef.h
)

add_executable(read_A8_via_B3 read_A8_via_B3.cxx MyClassB_3_dict.cxx)
target_link_libraries(read_A8_via_B3 ${ROOT_LIBRARIES} pthread)
