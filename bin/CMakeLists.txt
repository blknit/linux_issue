cmake_minimum_required(VERSION 2.8)
project(testbin)

SET(ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../..)

IF(ARCHITECTURE_32)
	SET(BUILD_ARCH x86)
	SET(ARCH_FLAGS -m32)
ELSE()
	SET(BUILD_ARCH x64)
	SET(ARCH_FLAGS -m64)
ENDIF(ARCHITECTURE_32)

set(SOURCES
	main.cpp
)

set(LINK_LIBS
	-static-libstdc++
	-static-libgcc
	libdl.so
)

set(COMPILER_FLAGS)
set(LINKER_FLAGS)

include_directories(/usr/lib)
include_directories(${INC})
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    COMPILE_FAGS "${COMPILER_FLAGS}" LINK_FLAGS "${LINKER_FLAGS}")
target_link_libraries(${PROJECT_NAME} PRIVATE ${LINK_LIBS})
cotire(${PROJECT_NAME})
