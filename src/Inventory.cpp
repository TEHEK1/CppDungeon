//
// Created by artem on 08.03.2024.
//
#include "Inventory.h"
#include <set>
void Inventory::addItem(Item *item) {
    m_items.insert(item);
}

void Inventory::removeItem(Item *item) {
    m_items.erase(item);
}

std::multiset<Item*> Inventory::getItems() {
    return m_items;
}