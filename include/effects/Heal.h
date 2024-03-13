//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_DAMAGE_H
#define CPPDUNGEON_DAMAGE_H
#include "effects/ImmediateEffect.h"
namespace effects {
    class Heal: public ImmediateEffect {
    public:
        Heal(std::weak_ptr<Entity>, int minHeal, int maxHeal, int crited, int critModifier = 150);
    };
}
#endif //CPPDUNGEON_DAMAGE_H
