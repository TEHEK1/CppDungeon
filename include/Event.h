//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_EVENT_H
#define UNTITLED_EVENT_H
#include "ActionsChanger.h"
#include <vector>
class Player;
class Action;
class Event:public ActionsChanger{
protected:
public:
    virtual void turn(Player*, int index);
    std::vector<Action*> getAvailableActions();
    virtual std::vector<std::vector<char>> draw();
protected:
    void addActions(Player*, Action*);
    void removeActions(Player*, Action*);
};
#endif //UNTITLED_EVENT_H
