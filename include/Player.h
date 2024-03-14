//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include "Inventory.h"
#include <memory>
#include <set>
#include <vector>
class Entity;
class Position;
class Map;
class Monitor;
namespace actions {
    class Action;
} // namespace actions
class Squad;
class Player{
    Position m_position;
    Inventory m_inventory;
    std::shared_ptr<Squad> m_squad;
    std::set<std::shared_ptr<actions::Action> > m_actions;
    friend class ActionChanger;
    friend class PositionChanger;
    friend class InventoryChanger;
    std::vector<std::shared_ptr<Entity> > m_heroes;
    Monitor* m_monitor;
    Map* m_map;
public:
    std::vector<std::shared_ptr<Entity> > getHeroes();
    Monitor* getMonitor();
    Position getPosition();
    std::shared_ptr<Squad> getSquad();
    std::set<std::shared_ptr<Action>> getActions();
    Inventory getInventory();
    Map* getMap();
};
#endif //UNTITLED_PLAYER_H
