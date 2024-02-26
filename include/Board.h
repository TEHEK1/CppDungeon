//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H
#include <vector>
#include <map>
#include "Cell.h"
class Player;
class Board{
public:
    std::vector <Player*> players;
    std::map <Player*, Cell*> playerCells;
    Cell getCurrentCell(Player*);
    void
};
#endif //UNTITLED_BOARD_H
