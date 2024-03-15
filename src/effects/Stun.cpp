//
// Created by artem on 12.03.2024.
//
#include <map>
#include "effects/Debuff.h"
#include "effects/Stun.h"
#include "entity/Trick.h"
namespace effects {
    Stun::Stun(std::weak_ptr<Entity> entity, int numberOfTurns) : Debuff(entity, numberOfTurns, std::map<size_t, int>{{trick::hash("turnable"), -1}}) {
    }
}