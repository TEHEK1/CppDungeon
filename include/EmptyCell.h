//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_EMPTYCELL_H
#define CPPDUNGEON_EMPTYCELL_H
#include "Event.h"
class EmptyCell:public Event{
    void turn(Player *, int) override;
    std::vector<std::vector<char>> draw() override;
};
#endif //CPPDUNGEON_EMPTYCELL_H
