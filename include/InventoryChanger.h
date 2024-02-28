//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_INVENTORYCHANGER_H
#define CPPDUNGEON_INVENTORYCHANGER_H
class Inventory;
class Player;
class InventoryChanger{
    Inventory& getInventory(Player*);
};
#endif //CPPDUNGEON_INVENTORYCHANGER_H
