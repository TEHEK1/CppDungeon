//
// Created by Владимир Попов on 08.03.2024
//
#include "InventoryChanger.h"
#include "Player.h"

Inventory& InventoryChanger::getInventory(Player *player){
    return player->inventory;
}

void InventoryChanger::addItem(Player* player, std::shared_ptr<Item> item) {
    player->inventory.addItem(item);
}

void InventoryChanger::removeItem(Player* player, std::shared_ptr<Item> item) {
    player->inventory.removeItem(item);
}