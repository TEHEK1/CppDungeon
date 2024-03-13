//
// Created by artem on 12.03.2024.
//
#include <map>
#include "Debuff.h"
#include "Stun.h"
#include "trick.h"
namespace effects {
    Stun::Stun(std::weak_ptr<Entity> entity, int numberOfTurns) : Debuff(entity, numberOfTurns, std::map<size_t, int>{{trick::hash("turnable"), -1}}) {
    }
}