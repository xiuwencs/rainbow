cmake_minimum_required(VERSION 3.2)
project(rainbow)
set(CMAKE_CXX_STANDARD 11)
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif(CMAKE_COMPILER_IS_GNUCXX)

option(ACTION "Allow Action or Phi Function" OFF)
if(ACTION)
	add_definitions("-DACTION")
	message(STATUS "Allow Action or Phi Function")
else()
	message(STATUS "Not Allow Action or Phi Function")
endif()
add_executable(rainbow main.cpp
        dictionary.h
        utils.h
        utils.cpp)
