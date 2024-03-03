//
// Created by kait on 3/3/24.
//
#include "DontUse.h"
#include "Chest.h"

DontUse::DontUse(Trap * trap, int index) {
    m_index = index;
    m_trap = trap;
}

void DontUse::act(Player* player) {
    m_trap -> dontUse(player, m_index);
}

Trap* DontUse::getChest(){
    return m_trap;
}