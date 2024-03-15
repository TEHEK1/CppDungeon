//
// Created by artem on 12.03.2024.
//
#include <map>
#include "effects/Buff.h"
#include "effects/Guard.h"
#include "entity/Trick.h"
namespace effects {
    Guard::Guard(int numberOfTurns, int defenceModifier):
    Buff(numberOfTurns, std::map<int, int>{{trick::hash("defence"), defenceModifier}}) {};
}