//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_TRAP_H
#define CPPDUNGEON_TRAP_H
#include "Chest.h"
class Player;
class Trap:public Chest{
public:
    void turn(Player *, int) override;
    void use(Player*, int) override;
    void dontUse(Player*, int);
    std::vector<std::vector<char>> draw() override;
};
#endif //CPPDUNGEON_TRAP_H
