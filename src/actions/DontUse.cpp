//
// Created by kait on 3/3/24.
//
#include "actions/DontUse.h"
#include "events/Trap.h"

namespace actions {
    DontUse::DontUse(const std::shared_ptr<Trap>& trap) : m_trap(trap){}

    void DontUse::act(Player *player) {
        m_trap->dontUse(player);
    }

    std::shared_ptr<Trap> DontUse::getTrap() const {
        return m_trap;
    }
}//namespace actions