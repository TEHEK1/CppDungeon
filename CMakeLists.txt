cmake_minimum_required(VERSION 3.24)
project(ugabuga)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(tests/MapTest)

include_directories(include)

add_executable(ugabuga
        tests/MapTest/main.cpp
        # src/Chest.cpp
        # src/EmptyCell.cpp
        # src/ChooseRoomEvent.cpp
        
        # src/Use.cpp
        # src/DontUse.cpp
        src/navigation/Position.cpp
        src/navigation/Map.cpp)
