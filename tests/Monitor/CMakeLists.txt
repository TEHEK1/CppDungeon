cmake_minimum_required(VERSION 3.24)
project(MonitorTest)

set(CMAKE_CXX_STANDARD 20)
find_package(PkgConfig REQUIRED)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(../../include)

add_executable(monitorTest
        main.cpp
        ../../src/monitor/Monitor.cpp
        ../../src/entity/Entity.cpp
        ../../src/player/Player.cpp
        ../../src/effects/PermanentEffect.cpp
        ../../src/Squad.cpp
        ../../src/navigation/Map.cpp
        ../../src/navigation/Cell.cpp
        ../../src/navigation/Hall.cpp
        ../../src/navigation/Room.cpp
        ../../src/navigation/Position.cpp
        ../../src/generators/NumberGenerator.cpp
        ../../src/events/ChooseRoomEvent.cpp
        ../../src/actions/ChooseNextRoom.cpp
        ../../src/changers/ActionsChanger.cpp
        ../../src/changers/PositionChanger.cpp
)
target_link_libraries(monitorTest ${CURSES_LIBRARIES})