//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_MAP_H
#define CPPDUNGEON_MAP_H
#include "Cell.h"
#include "Position.h"
class Map{
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
private:
    std::vector<std::vector<char>> m_contents;
    bool ValidForRoom(int line, int column) const;
    void GeneratePath(char A, char A_side, char B, char B_side) const; // creates path between A and B
    int getRandomValue(int seed);
    int m_size;
    std::vector< std::pair<int, int> > m_rooms;
    void CreatePath() const;
};
#endif //CPPDUNGEON_MAP_H
