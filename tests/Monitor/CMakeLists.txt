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
        ../../src/actions/MoveLeft.cpp
        ../../src/actions/MoveRight.cpp
        ../../src/events/Chest.cpp
        ../../src/actions/Use.cpp
        ../../src/actions/DontUse.cpp
        ../../src/events/Trap.cpp
        ../../src/changers/EffectChanger.cpp
        ../../src/effects/Damege.cpp
        ../../src/effects/ImmediateCharacteristicEffect.cpp
        ../../src/effects/ImmediateEffect.cpp
        ../../src/effects/MarkedAsTurnable.cpp
        ../../src/changers/EntityChanger.cpp
        ../../src/effects/MarkedAsEndBattle.cpp
        ../../src/events/EmptyCell.cpp
        ../../src/enemies/BrigandRaider/BrigandRaider.cpp
        ../../src/enemies/BrigandRaider/HarmlessPoke.cpp
        ../../src/enemies/BrigandRaider/Shank.cpp
        ../../src/enemies/BrigandRaider/SliceAndDice.cpp
        ../../src/enemies/BrigandRaider/UppercutSlice.cpp
        ../../src/skillDesignes/RangeSkill.cpp
        ../../src/skillDesignes/Skill.cpp
        ../../src/BattleField.cpp
        ../../src/entity/Enemy.cpp
        ../../src/effects/Mark.cpp
        ../../src/effects/Buff.cpp
        ../../src/effects/Debuff.cpp
        ../../src/effects/Move.cpp
        ../../src/effects/ForceMove.cpp
        ../../src/effects/Bleed.cpp
        ../../src/effects/AutoAction.cpp
        ../../src/BattleFieldChanger.cpp
        ../../src/SquadChanger.cpp
        ../../src/heroes/BountyHunter/BountyHunter.cpp
        ../../src/heroes/BountyHunter/MarkForDeath.cpp
        ../../src/heroes/BountyHunter/FinishHim.cpp
        ../../src/heroes/BountyHunter/FlashBang.cpp
        ../../src/heroes/BountyHunter/CollectBounty.cpp
        ../../src/heroes/BountyHunter/Caltrops.cpp
        ../../src/heroes/BountyHunter/ComeHither.cpp
        ../../src/heroes/BountyHunter/UpperCut.cpp
        ../../src/entity/Hero.cpp
)
target_link_libraries(monitorTest ${CURSES_LIBRARIES})