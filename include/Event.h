//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_EVENT_H
#define UNTITLED_EVENT_H
#include <vector>
#include "Action.h"
class Event{
public:
    virtual void turn();
    std::vector<Action*> getAvailableActions();
    std::vector<std::vector<char>> draw();
};
#endif //UNTITLED_EVENT_H
