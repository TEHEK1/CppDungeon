//
// Created by artem on 12.03.2024.
//
#include "effects/Debuff.h"

namespace effects {
    Debuff::Debuff(int numberOfTurns, std::map<int, int> modifier) : Buff(numberOfTurns, modifier) {}
    int Debuff::resistanceHash() {
        return static_cast<int>(Resistances::Debuff);
    }
} // namespace effects