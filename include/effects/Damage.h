//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_DAMAGE_H
#define CPPDUNGEON_DAMAGE_H
#include "effects/ImmediateEffect.h"
namespace effects {
    class Damage: public ImmediateEffect {
    public:
        Damage(std::weak_ptr<entity::Entity>, int minDamage, int maxDamage, int crited, int critModifier = 150);
    };
}
#endif //CPPDUNGEON_DAMAGE_H
