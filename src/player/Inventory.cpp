//
// Created by artem on 08.03.2024.
//
#include "player/Inventory.h"
#include <set>
void Inventory::addItem(const std::shared_ptr<Item>& item) {
    m_items.insert(item);
}

void Inventory::removeItem(const std::shared_ptr<Item>& item) {
    m_items.erase(item);
}

std::multiset<std::shared_ptr<Item>> Inventory::getItems() {
    return m_items;
}