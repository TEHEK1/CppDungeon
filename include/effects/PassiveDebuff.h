//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_PASSIVEDEBUFF_H
#define CPPDUNGEON_PASSIVEDEBUFF_H
#include "Debuff.h"
namespace effects {
    class PassiveDebuff: public Debuff {
        int m_numberOfBattles;
    public:
        void turn();
        virtual void endBattleTurn();
        int getRemainingBattles();
        PassiveDebuff(std::weak_ptr<entity::Entity>, int numberOfBattles, std::map<size_t, int> modifier);
    };
}
#endif //CPPDUNGEON_PASSIVEDEBUFF_H
