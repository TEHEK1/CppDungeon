//
// Created by artem on 13.03.2024.
//
#include <memory>
#include "random"
#include "effects/PercentHeal.h"
#include "entity/Trick.h"
#include "entity/Entity.h"
std::mt19937 rnd(time(0));
namespace effects {
    PercentHeal::PercentHeal(std::weak_ptr<entity::Entity> entity, int minPercentHeal, int maxPercentHeal, int crited, int critModifier) :
    ImmediateEffect(entity, std::map<size_t, int>{{trick::hash("HP"),crited < 0 ? entity.lock()->get(trick::hash("maxHP")) * (rnd() % (maxPercentHeal - minPercentHeal + 1) + minPercentHeal) : -maxPercentHeal * critModifier / 100}},
                    crited, critModifier) {
        if (minPercentHeal < 0 || minPercentHeal > maxPercentHeal) {
            throw "Incorrect value of minHeal";
        }
    };
}