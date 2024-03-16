//
// Created by artem on 12.03.2024.
//
#include "effects/Buff.h"
#include "entity/Entity.h"

namespace effects {
    Buff::Buff(int numberOfTurns, const std::map<int, int>& modifier) :
            PermanentEffect(modifier), MarkedAsTurnable(numberOfTurns), MarkedAsEndBattle(-1) {}
}
