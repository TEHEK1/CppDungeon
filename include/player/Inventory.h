//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_INVENTORY_H
#define CPPDUNGEON_INVENTORY_H
#include <memory>
#include <set>
#include <vector>
#include "namespaces/items.h"
#include "namespaces/changers.h"
class Inventory {
    std::multiset<std::shared_ptr<items::Item>> m_items;
    void addItem(const std::shared_ptr<items::Item>&);
    void removeItem(const std::shared_ptr<items::Item>&);
    friend changers::InventoryChanger;
public:
    std::multiset<std::shared_ptr<items::Item>> getItems();
};
#endif //CPPDUNGEON_INVENTORY_H
