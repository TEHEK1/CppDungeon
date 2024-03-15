cmake_minimum_required(VERSION 3.27)
project(CppDungeon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(include)

add_executable(CppDungeon
        src/Use.cpp
        src/MoveRight.cpp
        src/MoveLeft.cpp
        src/DontUse.cpp
        src/ChooseNextRoom.cpp
        src/Player.cpp
        src/PositionChanger.cpp
        src/Cell.cpp)
