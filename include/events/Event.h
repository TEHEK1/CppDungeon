//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_EVENT_H
#define UNTITLED_EVENT_H
#include "changers/ActionsChanger.h"
#include <vector>
class Player;
class Action;
class Event:public changers::ActionsChanger{
public:
    virtual void turn(Player*) = 0;
    virtual std::vector<std::vector<char> > draw() = 0;
    virtual ~Event() = default;
};
#endif //UNTITLED_EVENT_H
