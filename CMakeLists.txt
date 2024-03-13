cmake_minimum_required(VERSION 3.27)
project(CppDungeon)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(CppDungeon
        main.cpp
        src/Chest.cpp
        src/EmptyCell.cpp
        src/ChooseRoomEvent.cpp
        src/Use.cpp
        src/Cell.cpp
        src/Room.cpp
        src/Hall.cpp
        src/DontUse.cpp
        src/Player.cpp
        src/Inventory.cpp)
