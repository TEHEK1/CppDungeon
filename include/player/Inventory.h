//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_INVENTORY_H
#define CPPDUNGEON_INVENTORY_H
#include <memory>
#include <set>
#include <vector>

class Item;
namespace changers {
    class InventoryChanger;
} // namespace changers
class Inventory {
    std::multiset<std::shared_ptr<Item>> m_items;
    void addItem(const std::shared_ptr<Item>&);
    void removeItem(const std::shared_ptr<Item>&);
    friend changers::InventoryChanger;
public:
    std::multiset<std::shared_ptr<Item>> getItems();
};
#endif //CPPDUNGEON_INVENTORY_H