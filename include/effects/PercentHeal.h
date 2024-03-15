//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_PERCENTHEAL_H
#define CPPDUNGEON_PERCENTHEAL_H
#include "effects/ImmediateEffect.h"
namespace effects {
    class PercentHeal: ImmediateEffect {
    public:
        PercentHeal(std::weak_ptr<entity::Entity>, int minPercentHeal, int maxPercentHeal, int crited, int critModifier = 200);
    };
}
#endif //CPPDUNGEON_PERCENTHEAL_H
