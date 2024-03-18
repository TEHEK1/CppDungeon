//
// Created by Амир Кашапов on 18.03.2024.
//
#include <map>
#include "effects/Debuff.h"
#include "effects/Mark.h"
namespace effects {
    Mark::Mark(int numberOfTurns) : Debuff(numberOfTurns, std::map<int, int>{{static_cast<int>(Characteristic::marked), 1}}) {}
    int Mark::resistanceHash() {
        return static_cast<int>(Resistances::Debuff);
    }
}