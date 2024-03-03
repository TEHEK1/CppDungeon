cmake_minimum_required(VERSION 3.27)
project(CppDungeon)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(CppDungeon
        main.cpp
        src/Chest.cpp
        include/Action.h
        include/Board.h
        include/Cell.h
        include/Chest.h
        include/Enemy.h
        include/EnemyEncounter.h
        include/Entity.h
        include/Event.h
        include/Hall.h
        include/Hero.h
        include/Item.h
        include/Map.h
        include/Monitor.h
        include/Player.h
        include/Room.h
        include/Skill.h
        include/MoveLeft.h
        include/MoveRight.h
        include/ChooseNextRoom.h
        include/ChooseRoomEvent.h
        include/EmptyCell.h
        include/Use.h
        include/Trap.h
        include/DontUse.h
        include/Move.h
        include/Position.h
        include/UseSkill.h
        include/UseItem.h
        include/Boss.h
        include/NPC.h
        include/ActionsChanger.h
        include/PositionChanger.h
        include/SkillStorage.h
        src/Use.cpp
        src/DontUse.cpp)
