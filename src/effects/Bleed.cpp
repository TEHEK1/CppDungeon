//
// Created by artem on 13.03.2024.
//
#include "effects/Bleed.h"
namespace effects {
    Bleed::Bleed(int numberOfTurns, int HPturner):
    AutoAction(numberOfTurns, std::map<int, int>{{static_cast<int>(Characteristic::HP), HPturner}}){};
    int Bleed::resistanceHash() {
        return static_cast<int>(Resistances::Debuff);
    }
}