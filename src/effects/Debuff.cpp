//
// Created by artem on 12.03.2024.
//
#include "effects/Debuff.h"
#include "effects/Effect.h"
#include "Entity.h"

namespace effects {
    Debuff::Debuff(std::weak_ptr<Entity> entity, int numberOfTurns, std::map<size_t, int> modifier) : Effect(entity, modifier) {
        m_numberOfTurns = numberOfTurns;
    }

    int Debuff::getRemainingTurns() {
        return m_numberOfTurns;
    }

    void Debuff::turn() {
        --m_numberOfTurns;
        if (m_numberOfTurns < 0) {
            endBattleTurn();
        }
    }

    void Debuff::endBattleTurn() {
        std::shared_ptr<Entity> entity = m_entity.lock();
        if (entity) {
            (entity.get())->getEffects().erase(static_cast<std::shared_ptr<Effect>>(this));
        }
    }
}