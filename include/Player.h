//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include <vector>
#include <set>
class Hero;
class Position;
class Map;
class Monitor;
class Action;
class Player{
    std::set<Action*> actions;
    friend class Event;
public:
    std::vector<Hero*> getHeroes();
    Monitor* getMonitor();
    Position getPosition();
    std::set<Action*> getActions();
    Map* getMap();
};
#endif //UNTITLED_PLAYER_H
