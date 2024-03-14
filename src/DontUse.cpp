//
// Created by kait on 3/3/24.
//
#include "DontUse.h"
#include "Trap.h"

namespace actions {
    DontUse::DontUse(Trap *trap, int index) : m_trap(trap), m_index(index) {}

    void DontUse::act(Player *player) {
        m_trap->dontUse(player, m_index);
    }

    Trap *DontUse::getChest() {
        return m_trap;
    }
}