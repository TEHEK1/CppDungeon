//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H
#include "Event.h"
#include <vector>
class Cell{
public:
    void freeMoves(Player*, int);
    virtual void generateEvents() = 0;
    std::vector<Event*> getEvents();
    char getLevel();
    virtual ~Cell() = default;
};
#endif //UNTITLED_CELL_H
