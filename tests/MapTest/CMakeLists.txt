cmake_minimum_required(VERSION 3.24)
project(MapTest)

set(CMAKE_CXX_STANDARD 11)

include_directories(../../include)

add_executable(test
        main.cpp
        ../../src/navigation/Map.cpp
        ../../src/navigation/Position.cpp
        ../../src/navigation/Cell.cpp
        ../../src/navigation/Hall.cpp
        ../../src/navigation/Room.cpp
)
