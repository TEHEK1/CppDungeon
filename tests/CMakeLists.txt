cmake_minimum_required(VERSION 3.24)
project(Test)

set(CMAKE_CXX_STANDARD 20)

include_directories(../include ../src)

add_executable(test
        main.cpp
        ../include/Main.h
        ../src/Main.cpp
        ../include/eventfactory.h
        ../include/eventCreator.h
        ../include/abstractEventCreator.h
        ../include/events/Event.h
        ../include/events/ChooseRoomEvent.h
        ../include/events/Chest.h
        ../include/events/EmptyCell.h
        ../include/events/Trap.h
        ../src/events/ChooseRoomEvent.cpp
        ../src/events/Chest.cpp
        ../src/events/EmptyCell.cpp
        ../src/events/Trap.cpp
)