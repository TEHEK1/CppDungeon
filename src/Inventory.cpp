//
// Created by artem on 08.03.2024.
//
#include "Inventory.h"
#include <set>
void Inventory::addItem(std::shared_ptr<Item>& item) {
    m_items.insert(item);
}

void Inventory::removeItem(std::shared_ptr<Item>& item) {
    m_items.erase(item);
}

std::multiset<std::shared_ptr<Item>> Inventory::getItems() {
    return m_items;
}