cmake_minimum_required(VERSION 3.10)  # CMake version check
project(VRP)
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Add main.cpp file of project root directory as source file
include_directories(./src)

FIND_PACKAGE( Boost 1.72 REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.h) #local

#file(GLOB_RECURSE SRCS /vrp/src/*.cpp) #docker
#file(GLOB_RECURSE HDRS /vrp/src/*.h)

ADD_EXECUTABLE(VRP ${SRCS})

TARGET_LINK_LIBRARIES(VRP ${Boost_LIBRARIES})
