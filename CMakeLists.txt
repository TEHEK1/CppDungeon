cmake_minimum_required(VERSION 3.27)
project(CppDungeon)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(include)

add_executable(CppDungeon
        include/Action.h
        include/Board.h
        include/Boss.h
        include/Cell.h
        include/Chest.h
        include/ChooseNextRoom.h
        include/ChooseRoomEvent.h
        include/DontUse.h
        include/EmptyCell.h
        include/Enemy.h
        include/EnemyEncounter.h
        include/Entity.h
        include/Event.h
        include/Hall.h
        include/Hero.h
        include/Item.h
        include/Map.h
        include/Monitor.h
        include/Move.h
        include/MoveLeft.h
        include/MoveRight.h
        include/NPC.h
        include/Player.h
        include/Position.h
        include/Room.h
        include/Skill.h
        include/Trap.h
        include/Use.h
        include/UseItem.h
        include/UseSkill.h
        src/Use.cpp
        src/MoveRight.cpp
        src/MoveLeft.cpp
        src/DontUse.cpp
        src/ChooseNextRoom.cpp
)
