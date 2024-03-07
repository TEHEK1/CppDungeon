//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_MAP_H
#define CPPDUNGEON_MAP_H
#include "Cell.h"
#include "Position.h"
class Map{
public:
    Map(int);
    Map();
    Cell* getCell(Position);
    Position moveLeft(Position);
    Position moveRight(Position);
    void setRooms(Position&);
    std::vector<std::pair<int,int>> getNextRooms();
    Position chooseNextRoom(Position, std::pair<int,int>);
    std::pair<int,int> getNextRoom();
    std::vector<std::vector<char>> draw();
    int getSize();
};
#endif //CPPDUNGEON_MAP_H
