//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include <vector>
#include <set>
#include "Inventory.h"
#include "Position.h"

class Hero;
class Position;
class Map;
class Monitor;
class Action;
class Inventory;
class Player{
    Position position;
    Inventory inventory;
    std::set<Action*> actions;
    friend class ActionChanger;
    friend class PositionChanger;
public:
    std::vector<Hero*> getHeroes();
    Monitor* getMonitor();
    Position getPosition();
    std::set<Action*> getActions();
    Inventory getInventory();
    Map* getMap();
};
#endif //UNTITLED_PLAYER_H
