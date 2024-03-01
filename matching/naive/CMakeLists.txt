cmake_minimum_required(VERSION 3.2)
project(naive)
set(CMAKE_CXX_STANDARD 11)
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif(CMAKE_COMPILER_IS_GNUCXX)
add_executable(naive main.cpp
        dictionary.h
        utils.h
        utils.cpp)
