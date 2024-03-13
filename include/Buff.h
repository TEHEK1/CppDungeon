//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_BUFF_H
#define CPPDUNGEON_BUFF_H
#include "Effect.h"
namespace effects {
    class Buff: public Effect {
    int m_numberOfTurns;
    public:
        Buff(std::weak_ptr<Entity>, int numberOfTurns, std::map<size_t, int> modifier);
        int getRemainingTurns();
        void turn();
        virtual void endBattleTurn();
    };
}
#endif //CPPDUNGEON_BUFF_H
