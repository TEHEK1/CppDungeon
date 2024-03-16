//
// Created by artem on 13.03.2024.
//
#include "effects/Damage.h"
#include "entity/Trick.h"
#include "random"
namespace effects {
    Damage::Damage(int damage) :
    ImmediateEffect(std::map<int, int>{{trick::hash("HP"), std::max(-damage, 0)}}){}
}