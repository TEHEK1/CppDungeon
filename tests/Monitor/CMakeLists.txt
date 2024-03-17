cmake_minimum_required(VERSION 3.24)
project(MonitorTest)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig)
pkg_search_module(NCURSES REQUIRED ncurses)

include_directories(../../include)

include_directories (${NCURSES_INCLUDE_DIRS})
link_directories (${NCURSES_LIBRARY_DIRS})

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
)
add_definitions (${NCURSES_CXXFLAGS_OTHER})
target_link_libraries (monitorTest ${NCURSES_LIBRARIES})