//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_INVENTORYCHANGER_H
#define CPPDUNGEON_INVENTORYCHANGER_H
#include "items/Item.h"
#include <memory>
class Inventory;
class Player;
namespace changers{
    class InventoryChanger {
    protected:
        static Inventory &getInventory(Player *);

        static void addItem(Player *, const std::shared_ptr<items::Item> &item);

        static void removeItem(Player *, const std::shared_ptr<items::Item> &item);
    };
} // namespace changers
#endif //CPPDUNGEON_INVENTORYCHANGER_H
