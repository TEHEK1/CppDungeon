//
// Created by artem on 13.03.2024.
//
#include "effects/Damage.h"
#include "trick.h"
#include "random"
std::mt19937 rnd(time(0));
namespace effects {
    Damage::Damage(std::weak_ptr<Entity> entity, int minDamage, int maxDamage, int crited, int critModifier) :
    ImmediateEffect(entity, std::map<size_t, int>{{trick::hash("HP"), crited < 0 ? (rnd() % ((maxDamage - minDamage + 1)) + minDamage) : -maxDamage * critModifier / 100}}, crited, critModifier) {
        if (minDamage < 0 || minDamage > maxDamage) {
            throw "Incorrect value of minDamage";
        }
    }
}