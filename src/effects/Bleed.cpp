//
// Created by artem on 13.03.2024.
//
#include "effects/Bleed.h"
#include "entity/Trick.h"
namespace effects {
    Bleed::Bleed(int numberOfTurns, int HPturner):
    AutoAction(numberOfTurns, std::map<int, int>{{trick::hash("HP"), HPturner}}){};
    int Bleed::resistanceHash() {
        return static_cast<int>(Resistances::Debuff);
    }
}