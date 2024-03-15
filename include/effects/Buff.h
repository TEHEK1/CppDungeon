//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_BUFF_H
#define CPPDUNGEON_BUFF_H
#include "effects/Effect.h"
#include "changers/EntityChanger.h"
namespace effects {
    class Buff: public Effect {
    int m_numberOfTurns;
    public:
        ~Buff() override = default;
        Buff(const std::weak_ptr<entity::Entity>& entity, int numberOfTurns, const std::map<size_t, int>& modifier);
        int getRemainingTurns();
        void turn() override;
        void endBattleTurn() override;
    };
}
#endif //CPPDUNGEON_BUFF_H
