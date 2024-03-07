//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_ACTION_H
#define CPPDUNGEON_ACTION_H
class Player;
class Action{

public:
    virtual void act(Player*) = 0;
    virtual ~Action() = default;
};
#endif //CPPDUNGEON_ACTION_H
