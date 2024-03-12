//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_MAP_H
#define CPPDUNGEON_MAP_H
#include "Cell.h"
#include "Position.h"
#include <queue>
#include <ctime>
#include <random>

class Map final {
public:
    explicit Map(int);
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
    void PrintWholeMap();
private:
    std::vector<std::vector<char>> m_contents;
    bool ValidForRoom(int line, int column) const;
    bool ValidForCoridor(int line, int column) const;
    int m_size;
    std::vector< std::pair<int, int> > m_rooms;
    bool CreatePath (char begin_line, char begin_column, char end_line, char end_column, int seed, bool main_call);
    void DeleteNewCoridors();
    void SolidifyNewCoridors();
    void HolocaustCoridors();
    std::mt19937 generator;
};

#endif //CPPDUNGEON_MAP_H
