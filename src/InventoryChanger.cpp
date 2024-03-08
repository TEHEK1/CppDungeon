//
// Created by Владимир Попов on 08.02.2024
//
#include "InventoryChanger.h"
#include "Player.h"

Inventory& InventoryChanger::getInventory(Player *player){
    return player->inventory;
}