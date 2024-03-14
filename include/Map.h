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
    explicit Map(int); // done
    Map(); // done
    std::shared_ptr<Cell> getCell(Position); // done
    Position moveLeft(Position);
    Position moveRight(Position);
    void setRooms(Position&);
    std::vector<Position> getNextRooms(Position); // done
    Position chooseNextRoom(Position, std::pair<int,int>);
    std::pair<int,int> getNextRoom();
    std::vector<std::vector<char>> draw(); // done
    int getSize(); // done
    int getSeed(); // done
private:
    std::vector<std::vector<char>> m_contents;
    std::vector<std::vector<std::shared_ptr<Cell>>> m_cells;
    std::vector<std::vector<char>> m_edges;
    std::vector<Position> m_roomPositions;
    bool validForRoom(int line, int column) const;
    bool validForHall(int line, int column) const;
    int m_size;
    int generatorSeed;
    std::vector< std::pair<int, int> > m_rooms;
    bool createPath (char begin_line, char begin_column, char end_line, char end_column, int seed, bool main_call);
    void deleteNewHalls();
    void solidifyNewHalls();
    void holocaustHalls();
    std::mt19937 generator;
};

#endif //CPPDUNGEON_MAP_H
