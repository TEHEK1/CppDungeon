cmake_minimum_required(VERSION 3.24)
project(ugabuga)

set(CMAKE_C_STANDARD 11)

add_subdirectory(tests/MapTest)

include_directories(include)

add_executable(CppDungeon
        src/actions/Use.cpp
        src/actions/MoveRight.cpp
        src/actions/MoveLeft.cpp
        src/actions/DontUse.cpp
        src/actions/ChooseNextRoom.cpp
        src/player/Player.cpp
        src/changers/PositionChanger.cpp
        src/navigation/Cell.cpp
        src/events/Trap.cpp
        src/events/Chest.cpp
        src/Item/Item.cpp
        include/items/LickWounds.h
        include/items/FortifyingGarlic.h
        src/Item/LickWounds.cpp
        src/Item/FortifyingGarlic.cpp
        include/items/FortifyingGarlicEffect.h
        src/Item/FortifyingGarlicEffect.cpp
        include/items/BloodiedNeckerchief.h
        include/items/BloodiedNeckerchiefEffect.h
        src/Item/BloodiedNeckerchief.cpp
        src/Item/BloodiedNeckerchiefEffect.cpp
        include/items/Absinthe.h
        include/items/AbsintheEffect.h
        src/Item/Absinthe.cpp
        src/Item/AbsintheEffect.cpp
)