//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_DONTUSE_H
#define CPPDUNGEON_DONTUSE_H
#include "Action.h"
#include "Trap.h"
class Chest;
class DontUse:public Action{
public:
    DontUse(Trap*, int);
    void act(Player*) override;
    Trap* getChest();
private:
    int m_index;
    Trap* m_trap;
};
#endif //CPPDUNGEON_DONTUSE_H
