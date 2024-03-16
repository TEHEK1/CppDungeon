//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_DAMAGE_H
#define CPPDUNGEON_DAMAGE_H
#include "effects/ImmediateCharacteristicEffect.h"
namespace effects {
    class Damage: public ImmediateCharacteristicEffect {
    public:
        Damage(int damage);
    };
}
#endif //CPPDUNGEON_DAMAGE_H
