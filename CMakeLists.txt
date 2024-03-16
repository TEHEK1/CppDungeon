cmake_minimum_required(VERSION 3.24)
project(ugabuga)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(tests/MapTest)

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
        src/events/Trap.cpp
        src/events/Chest.cpp
        src/events/ChooseRoomEvent.cpp)
