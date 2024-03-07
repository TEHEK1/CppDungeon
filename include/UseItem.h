//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_USEITEM_H
#define CPPDUNGEON_USEITEM_H
#include "Action.h"
#include <vector>
#include <memory>
class Entity;
class Item;
class UseItem: public Action{
public:
    UseItem(Player* player, Item* item, std::vector<std::shared_ptr<Entity>> entities);
    void act(Player*) override;
};
#endif //CPPDUNGEON_USEITEM_H
