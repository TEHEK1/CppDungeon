//
// Created by kait on 2/29/24.
//
#include "include/Use.h"
#include "include/Chest.h"

Use::Use(Chest* chest, int index){
    m_index = index;
    m_chest = chest;
}

void Use::act(Player * player) {
    m_chest -> use(player, m_index);
}

Chest* Use::getChest(){
    return m_chest;
}