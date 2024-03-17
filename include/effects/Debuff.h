//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_DEBUFF_H
#define CPPDUNGEON_DEBUFF_H
#include "effects/Buff.h"
#include "changers/EntityChanger.h"
#include "effects/MarkedAsResistable.h"
namespace effects {
    class Debuff: public Buff, public MarkedAsResistable {
    public:
        Debuff(int numberOfTurns, std::map<int, int> modifier);
        int resistanceHash() override;
    };
} //namespace effects
#endif //CPPDUNGEON_DEBUFF_H
