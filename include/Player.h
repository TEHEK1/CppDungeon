//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "Inventory.h"
#include "Position.h"
#include <memory>
#include <set>
#include <vector>

class Entity;
class Position;
class Map;
class Monitor;
class Hero;
class Action;
class Inventory;
class Player{
    Position position;
    Inventory inventory;
    std::set<std::unique_ptr<Action>> actions;
    friend class ActionChanger;
    friend class PositionChanger;
    friend class InventoryChanger;
    std::vector<std::shared_ptr<Entity>> heroes;
    Monitor* monitor;
    Map* map;
public:
    std::vector<std::shared_ptr<Entity>> getHeroes();
    Monitor* getMonitor();
    Position getPosition();
    std::set<std::unique_ptr<Action>> getActions();
    Inventory getInventory();
    Map* getMap();
};
#endif //UNTITLED_PLAYER_H
