//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_MOVELEFT_H
#define CPPDUNGEON_MOVELEFT_H
#include "Action.h"
#include "ActionsChanger.h"
#include "PositionChanger.h"
class MoveLeft:public Action, public ActionsChanger, public PositionChanger{
public:
    void act(Player*) override;
};
#endif //CPPDUNGEON_MOVELEFT_H
