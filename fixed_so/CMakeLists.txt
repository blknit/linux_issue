cmake_minimum_required(VERSION 3.5.1)
project(fixedso)

SET(LIBRARY_FILE_EXTENSION so)
SET(ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=gold")

IF(ARCHITECTURE_32)
	SET(BUILD_ARCH x86)
	SET(ARCH_FLAGS -m32)
ELSE()
	SET(BUILD_ARCH x64)
	SET(ARCH_FLAGS -m64)
ENDIF(ARCHITECTURE_32)

# Compiler configuration
SET(CMAKE_CXX_STANDARD 14)

# default to debug build
IF(NOT DEFINED CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT DEFINED CMAKE_BUILD_TYPE)

# Do not embed rpath into the produced binary
SET(CMAKE_SKIP_BUILD_RPATH FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
SET(CMAKE_INSTALL_RPATH "\$ORIGIN")

set(SOURCES
	fixed.cpp
)

set(LINK_LIBS
	-Wl,--whole-archive
	-Wl,-Bstatic
	stdc++
	gcc
	gcc_eh
	-Wl,-Bdynamic
	-Wl,--no-whole-archive
	m
	c
)

# Define compiler flags for this library: #  -fPIC  -msse -msse2 -msse3 -Wl,-z,defs
set(COMPILE_PARAM COMPILE_FLAGS "${ARCH_FLAGS} -fPIC  -msse -msse2 -msse3 -Wl,-z,defs -fvisibility=hidden")
set(LINK_PARAM LINK_FLAGS "${ARCH_FLAGS} ${LINK_FLAGS} -nostdlib -Wl,--no-undefined -Wl,--no-gnu-unique")

# Build instructions
add_library(${PROJECT_NAME} SHARED ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
	${COMPILE_PARAM}
	${LINK_PARAM}
	${VERSION_PARAM}
	${SOVERSION_PARAM})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LINK_LIBS} ${CMAKE_DL_LIBS})
cotire(${PROJECT_NAME})


