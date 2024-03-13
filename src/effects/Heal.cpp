//
// Created by artem on 13.03.2024.
//
#include "effects/Heal.h"
#include "trick.h"
#include "random"
std::mt19937 rnd(time(0));
namespace effects {
    Heal::Heal(std::weak_ptr<Entity> entity, int minHeal, int maxHeal, int crited, int critModifier) :
            ImmediateEffect(entity, std::map<size_t, int>{{trick::hash("HP"), crited < 0 ? (rnd() % ((maxHeal - minHeal + 1)) + minHeal) : -maxHeal * critModifier / 100}}, crited, critModifier) {
        if (minHeal < 0 || minHeal > maxHeal) {
            throw "Incorrect value of minHeal";
        }
    }
}