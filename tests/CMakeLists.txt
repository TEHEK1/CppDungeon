cmake_minimum_required(VERSION 3.27)
project(Test)

set(CMAKE_CXX_STANDARD 11)

include_directories(../include)

add_executable(test
        main.cpp
        ../src/Cell.cpp
        ../src/Hall.cpp
        ../src/Room.cpp
        ../src/Map.cpp)
