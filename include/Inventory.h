//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_INVENTORY_H
#define CPPDUNGEON_INVENTORY_H
#include <vector>
class Item;
class Inventory{
    void addItem(Item*);
    void removeItem(Item*);
    std::vector<Item*> getItems();
};
#endif //CPPDUNGEON_INVENTORY_H
