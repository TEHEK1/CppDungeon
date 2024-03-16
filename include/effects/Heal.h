//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_HEAL_H
#define CPPDUNGEON_HEAL_H
#include "effects/ImmediateCharacteristicEffect.h"
namespace effects {
    class Heal: public ImmediateCharacteristicEffect {
    public:
        Heal(int heal);
    };
}
#endif //CPPDUNGEON_HEAL_H
