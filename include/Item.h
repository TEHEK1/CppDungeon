//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_ITEM_H
#define CPPDUNGEON_ITEM_H
#include "Skill.h"
class Item:public Skill{
public:
    virtual ~Item() = default;
};
#endif //CPPDUNGEON_ITEM_H
