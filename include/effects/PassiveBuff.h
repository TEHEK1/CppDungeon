//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_PASSIVEBUFF_H
#define CPPDUNGEON_PASSIVEBUFF_H
#include "PermanentEffect.h"
#include "MarkedAsEndBattle.h"
namespace effects {
    class PassiveBuff: public PermanentEffect, public MarkedAsEndBattle {
    public:
        PassiveBuff(int numberOfBattles, std::map<int, int> modifier);
    };
} // namespace effects
#endif //CPPDUNGEON_PASSIVEBUFF_H
