cmake_minimum_required(VERSION 3.13)  # CMake version check
project(VRP)
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
include_directories(src)

FIND_PACKAGE( Boost 1.72 REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.h)

ADD_EXECUTABLE(VRP ${SRCS})

TARGET_LINK_LIBRARIES(VRP ${Boost_LIBRARIES})
