//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_USEITEM_H
#define CPPDUNGEON_USEITEM_H
#include "Action.h"
#include <vector>
class Entity;
class Item;
class UseSkill: public Action{
public:
    UseSkill(Entity* actor, Item* item, std::vector<Entity*> entities);
    void act(Player*) override;
};
#endif //CPPDUNGEON_USEITEM_H
