//
// Created by artem on 08.03.2024.
//
#include "actions/Action.h"
#include "entity/Entity.h"
#include "player/Inventory.h"
#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Position.h"
#include "navigation/Map.h"
#include "Squad.h"
#include <memory>

//Player::Player(Map *map):m_map(map), m_position(map->getStartPosition()) {
//    m_squad = std::make_shared<Squad>(std::vector<std::shared_ptr<entity::Entity>>(2));
//}

Monitor* Player::getMonitor() {
    return m_monitor;
}
//void Player::setMonitor(Monitor *monitor) {
//    m_monitor = monitor;
//}
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

std::set<std::shared_ptr<actions::Action>> Player::getActions() {
    return m_actions;
}