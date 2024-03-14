cmake_minimum_required(VERSION 3.27)
project(ugabuga)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(ugabuga
        tests/main.cpp
        # src/Chest.cpp
        # src/EmptyCell.cpp
        # src/ChooseRoomEvent.cpp
        
        # src/Use.cpp
        # src/DontUse.cpp
        src/Position.cpp
        src/Map.cpp)
