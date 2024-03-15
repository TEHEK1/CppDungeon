//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include "player/Inventory.h"
#include "navigation/Position.h"
#include <memory>
#include <set>
#include <vector>
class Entity;
class Map;
class Monitor;
namespace actions {
    class Action;
} // namespace actions
namespace changers {
    class ActionChanger;
    class PositionChanger;
    class InventoryChanger;
} // namespace changers
class Squad;
class Player{
    Position m_position;
    Inventory m_inventory;
    std::shared_ptr<Squad> m_squad;
    std::set<std::shared_ptr<actions::Action>> m_actions;
    friend changers::ActionChanger;
    friend changers::PositionChanger;
    friend changers::InventoryChanger;
    std::vector<std::shared_ptr<Entity>> m_heroes;
    Monitor* m_monitor;
    Map* m_map;
public:
    std::vector<std::shared_ptr<Entity>> getHeroes();
    Monitor* getMonitor();
    Position getPosition();
    std::shared_ptr<Squad> getSquad();
    std::set<std::shared_ptr<actions::Action>> getActions();
    Inventory getInventory();
    Map* getMap();
};
#endif //UNTITLED_PLAYER_H
