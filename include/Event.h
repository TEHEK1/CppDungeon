//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_EVENT_H
#define UNTITLED_EVENT_H
#include <vector>
#include "ActionsChanger.h"
class Player;
class Action;
class Event:ActionsChanger{
public:
    virtual void turn(Player*, int);
    virtual std::vector<std::vector<char>> draw();
};
#endif //UNTITLED_EVENT_H
