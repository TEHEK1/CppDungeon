//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "Inventory.h"
#include "Position.h"
#include <set>
#include <vector>

class Entity;
class Position;
class Map;
class Monitor;
class Action;
class Inventory;
class Player{
    Position position;
    Inventory inventory;
    std::set<std::shared_ptr<Action>> actions;
    friend class ActionChanger;
    friend class PositionChanger;
    friend class InventoryChanger;
public:
    std::vector<std::shared_ptr<Entity>> getHeroes();
    Monitor* getMonitor();
    Position getPosition();
    std::set<std::shared_ptr<Action>> getActions();
    Inventory getInventory();
    Map* getMap();
};
#endif //UNTITLED_PLAYER_H
