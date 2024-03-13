//
// Created by artem on 12.03.2024.
//
#include <map>
#include "Buff.h"
#include "Guard.h"
#include "trick.h"
namespace effects {
    Guard::Guard(std::weak_ptr<Entity> entity, int numberOfTurns, int defenceModifier): Buff(entity, numberOfTurns, std::map<size_t, int>{{trick::hash("defence"), defenceModifier}}) {};
}