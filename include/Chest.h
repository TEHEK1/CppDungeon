//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_CHEST_H
#define CPPDUNGEON_CHEST_H
#include "Event.h"
class Player;
class Chest:public Event{
public:
    void use(Player*, int);
};
#endif //CPPDUNGEON_CHEST_H
