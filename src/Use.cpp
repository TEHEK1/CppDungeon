//
// Created by kait on 3/3/24.
//
#include "Use.h"
#include "Chest.h"

Use::Use(Chest* chest, int index):m_chest(chest), m_index(index){}

void Use::act(Player* player){
    m_chest -> use(player, m_index);
}

Chest *Use::getChest() {
    return m_chest;
}