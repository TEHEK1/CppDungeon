//
// Created by artem on 12.03.2024.
//
#include <map>
#include "effects/Debuff.h"
#include "effects/Stun.h"
namespace effects {
    Stun::Stun(int numberOfTurns) : Debuff(numberOfTurns, std::map<int, int>{{static_cast<int>(Characteristic::turnable), -1}}) {}
    int Stun::resistanceHash() {
        return static_cast<int>(Resistances::Stun);
    }
}