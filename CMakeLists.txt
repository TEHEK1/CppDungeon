cmake_minimum_required(VERSION 3.24)
project(ugabuga)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(tests/MapTest)

include_directories(include)


add_executable(CppDungeon
        main.cpp
        src/entity/Entity.cpp
        src/Squad.cpp
        src/SquadChanger.cpp
        src/BattleFieldChanger.cpp
        src/BattleField.cpp)
