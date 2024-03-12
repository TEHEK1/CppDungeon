//
// Created by artem on 08.03.2024.
//
#include "Action.h"
#include "Entity.h"
#include <memory>
#include "Monitor.h"
#include "Position.h"
#include "Player.h"
#include "Inventory.h"

std::vector<std::shared_ptr<Entity>> Player::getHeroes() {
    return m_heroes;
}

Monitor* Player::getMonitor() {
    return m_monitor;
}

Position Player::getPosition() {
    return m_position;
}

std::shared_ptr<Squad> Player::getSquad() {
    return m_squad;
}

Inventory Player::getInventory() {
    return m_inventory;
}

Map* Player::getMap() {
    return m_map;
}

std::set<std::shared_ptr<Action>> Player::getActions() {
    return m_actions;
}