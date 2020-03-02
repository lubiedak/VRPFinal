cmake_minimum_required(VERSION 3.13)  # CMake version check
project(VRP)
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
include_directories(src)
set(SOURCE_FILES src/VRPCore.cpp)

FIND_PACKAGE( Boost 1.72 REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

ADD_EXECUTABLE(VRP ${SRCS} ${HDRS})

TARGET_LINK_LIBRARIES(VRP ${Boost_LIBRARIES} ${SRCS} ${HDRS})
