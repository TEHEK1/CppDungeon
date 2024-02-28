//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_CHEST_H
#define CPPDUNGEON_CHEST_H
#include "Event.h"
class Player;
class Chest:public Event{
public:
    void turn(Player *, int) override;
    void use(Player*, int);
    std::vector<std::vector<char>> draw() override;
};
#endif //CPPDUNGEON_CHEST_H
