//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include "Hero.h"
#include "Board.h"
#include "Item.h"
#include <vector>
class Player{
    std::vector <Hero> squad;
    Board* board;
    std::vector <Item> inventory;
};
#endif //UNTITLED_PLAYER_H
