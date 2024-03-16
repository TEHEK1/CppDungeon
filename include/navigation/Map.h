//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_MAP_H
#define CPPDUNGEON_MAP_H
#include "navigation/Cell.h"
#include "navigation/Position.h"
class Map{
public:
    explicit Map(int);
    Map();
    std::shared_ptr<Cell> getCell(Position);
    Position moveLeft(Position);
    Position moveRight(Position);
    void setRooms(Position&);
    std::vector<int> getNextRooms();
    Position chooseNextRoom(Position, char);
    std::pair<int,int> getNextRoom();
    std::vector<std::vector<char>> draw();
    int getSize();
};
#endif //CPPDUNGEON_MAP_H
