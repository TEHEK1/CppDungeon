//
// Created by artem on 15.03.2024.
//

#ifndef CPPDUNGEON_MAIN_H
#define CPPDUNGEON_MAIN_H
#include "memory"
class Monitor;
class Event;
class Entity;
class Main {
public:
    void setSeed(std::size_t);
    std::size_t getSeed();
    Monitor* getGame();
    Event getEvent();
    Entity getEntity();
};
#endif //CPPDUNGEON_MAIN_H
