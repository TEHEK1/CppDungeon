cmake_minimum_required(VERSION 3.27)
project(CppDungeon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(include)

add_executable(CppDungeon
        main.cpp
        src/entity/Entity.cpp
        src/Squad.cpp
        src/SquadChanger.cpp
        src/BattleFieldChanger.cpp
        src/BattleField.cpp)

