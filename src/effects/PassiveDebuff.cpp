//
// Created by artem on 12.03.2024.
//
#include "effects/PassiveDebuff.h"
namespace effects {
    PassiveDebuff::PassiveDebuff(int numberOfBattles, std::map<int, int> modifier):
    PassiveBuff(numberOfBattles, modifier){}
    int PassiveDebuff::resistanceHash() {
        return static_cast<int>(Resistances::Debuff);
    }
}