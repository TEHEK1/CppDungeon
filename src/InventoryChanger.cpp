//
// Created by Владимир Попов on 08.03.2024
//
#include "InventoryChanger.h"
#include "Player.h"

Inventory& InventoryChanger::getInventory(Player *player){
    return player->m_inventory;
}

void InventoryChanger::addItem(Player* player, std::shared_ptr<Item> item) {
    player->m_inventory.addItem(item);
}

void InventoryChanger::removeItem(Player* player, std::shared_ptr<Item> item) {
    player->m_inventory.removeItem(item);
}