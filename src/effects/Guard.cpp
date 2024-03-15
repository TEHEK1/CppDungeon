//
// Created by artem on 12.03.2024.
//
#include <map>
#include "effects/Buff.h"
#include "effects/Guard.h"
#include "entity/Trick.h"
namespace effects {
    Guard::Guard(std::weak_ptr<Entity> entity, int numberOfTurns, int defenceModifier): Buff(entity, numberOfTurns, std::map<size_t, int>{{trick::hash("defence"), defenceModifier}}) {};
}