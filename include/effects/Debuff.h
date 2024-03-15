//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_DEBUFF_H
#define CPPDUNGEON_DEBUFF_H
#include "effects/Effect.h"
#include "changers/EntityChanger.h"
namespace effects {
    class Debuff: public Effect {
        int m_numberOfTurns;
    public:
        Debuff(std::weak_ptr<Entity>, int numberOfTurns, std::map<size_t, int> modifier);
        int getRemainingTurns();
        void turn();
        virtual void endBattleTurn();
    };

}
#endif //CPPDUNGEON_DEBUFF_H
