//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_CHEST_H
#define CPPDUNGEON_CHEST_H
#include "Event.h"
#include "InventoryChanger.h"
class Player;
class Chest:public Event, public InventoryChanger{
    bool used;
    bool comp(std::set<std::unique_ptr<Action>>::iterator actionIterator);
public:
    void turn(Player *, int) override;
    void use(Player*, int);
    void dontUse(Player*, int);
    std::vector<std::vector<char>> draw() override;
};
#endif //CPPDUNGEON_CHEST_H
