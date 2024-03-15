//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_PASSIVEDEBUFF_H
#define CPPDUNGEON_PASSIVEDEBUFF_H
#include "effects/PassiveBuff.h"
#include "effects/MarkedAsResistable.h"
namespace effects {
    class PassiveDebuff: public PassiveBuff, public MarkedAsResistable {
    public:
        PassiveDebuff(int numberOfBattles, std::map<int, int> modifier);
        int resistanceHash() override;
    };
} // namespace effects
#endif //CPPDUNGEON_PASSIVEDEBUFF_H
