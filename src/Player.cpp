//
// Created by artem on 08.03.2024.
//
#include "Player.h"
#include "Monitor.h"
#include "Position.h"
#include "Inventory.h"
#include "Action.h"
#include "Entity.h"
#include "memory"

std::vector<std::shared_ptr<Entity>> Player::getHeroes() {
    return Player::heroes;
}

Monitor* Player::getMonitor() {
    return Player::monitor;
}

Position Player::getPosition() {
    return Player::position;
}

std::set<std::unique_ptr<Action>> Player::getActions() {
    return Player::actions;
}

Inventory Player::getInventory() {
    return Player::inventory;
}

Map* Player::getMap() {
    return Player::map;
}