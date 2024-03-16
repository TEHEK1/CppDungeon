cmake_minimum_required(VERSION 3.27)
project(CppDungeon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(include)

add_executable(CppDungeon
        src/actions/Use.cpp
        src/actions/MoveRight.cpp
        src/actions/MoveLeft.cpp
        src/actions/DontUse.cpp
        src/actions/ChooseNextRoom.cpp
        src/player/Player.cpp
        src/changers/PositionChanger.cpp
        src/navigation/Cell.cpp
        include/eventCreator.h
        include/eventfactory.h
        include/abstractEventCreator.h
        main.cpp
        src/Main.cpp)