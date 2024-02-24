//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H
#include "Cell.h"
class Player;
#include <vector>
class Board{
    std::vector<std::vector<Cell>> map;
public:
    std::vector <Player*> players;
    Cell getCurrentCell(Player*);
};
#endif //UNTITLED_BOARD_H
