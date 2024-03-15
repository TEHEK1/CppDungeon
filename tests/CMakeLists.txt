cmake_minimum_required(VERSION 3.24)
project(Test)

set(CMAKE_CXX_STANDARD 20)

include_directories(../include)

add_executable(test
        main.cpp
        ../src/effects/AutoAction.cpp
        ../src/effects/Effect.cpp
        ../src/effects/Buff.cpp
        ../src/effects/ImmediateEffect.cpp
        ../src/entity/Entity.cpp
        ../src/changers/EffectChanger.cpp
        ../src/changers/EntityChanger.cpp
        EffectTest.cpp
        EffectTest.h
        ../src/effects/Buff.cpp
        ../src/effects/PermanentEffect.cpp
        ../include/effects/MarkedAsResistable.h
        ../include/effects/MarkedAsBattleFieldNeeded.h
        ../include/effects/MarkedAsTurnable.h
)