//
// Created by kait on 3/3/24.
//
#include "DontUse.h"
#include "Trap.h"

namespace actions {
    DontUse::DontUse(const std::shared_ptr<Trap>& trap, int index) : m_trap(trap), m_index(index) {}

    void DontUse::act(Player *player) {
        m_trap->dontUse(player, m_index);
    }

    std::shared_ptr<Trap> DontUse::getTrap() const {
        return m_trap;
    }
}//namespace actions