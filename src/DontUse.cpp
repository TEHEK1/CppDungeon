//
// Created by kait on 3/3/24.
//
#include "DontUse.h"
#include "Chest.h"

DontUse::DontUse(Chest * chest, int index) {
    m_index = index;
    m_chest = chest;
}

void DontUse::act(Player* player) {
    m_chest -> dontUse(player, m_index);
}

Chest* DontUse::getChest(){
    return m_chest;
}