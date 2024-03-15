//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_PASSIVEBUFF_H
#define CPPDUNGEON_PASSIVEBUFF_H
#include "Buff.h"
#include "changers/EntityChanger.h"
namespace effects {
    class PassiveBuff: public Buff {
        int m_numberOfBattles;
    public:
        void turn();
        virtual void endBattleTurn();
        int getRemainingBattles();
        PassiveBuff(std::weak_ptr<entity::Entity>, int numberOfBattles, std::map<size_t, int> modifier);
    };
}
#endif //CPPDUNGEON_PASSIVEBUFF_H
