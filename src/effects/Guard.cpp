//
// Created by artem on 12.03.2024.
//
#include <map>
#include "effects/Buff.h"
#include "effects/Guard.h"
namespace effects {
    Guard::Guard(int numberOfTurns, int defenceModifier):
    Buff(numberOfTurns, std::map<int, int>{{static_cast<int>(Characteristic::defence), defenceModifier}}) {};
}