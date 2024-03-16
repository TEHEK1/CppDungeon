cmake_minimum_required(VERSION 3.27)
project(CppDungeon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(include)

add_executable(CppDungeon
<<<<<<< HEAD
        src/Entity.cpp
        src/EntityChanger.cpp
        src/effects/Effect.cpp)

=======
        src/actions/Use.cpp
        src/actions/MoveRight.cpp
        src/actions/MoveLeft.cpp
        src/actions/DontUse.cpp
        src/actions/ChooseNextRoom.cpp
        src/player/Player.cpp
        src/changers/PositionChanger.cpp
        src/navigation/Cell.cpp)
>>>>>>> dev
