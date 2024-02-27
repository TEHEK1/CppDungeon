//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_DONTUSE_H
#define CPPDUNGEON_DONTUSE_H
#include "Action.h"
class Chest;
class DontUse:public Action{
public:
    DontUse(Chest*, int)
    void act() override;
};
#endif //CPPDUNGEON_DONTUSE_H
