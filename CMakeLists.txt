cmake_minimum_required(VERSION 3.27)
project(CppDungeon)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(CppDungeon
        Entity.CPP
        EntityChanger.cpp
        Effect.cpp
        Skill.cpp)

