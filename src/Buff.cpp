//
// Created by artem on 12.03.2024.
//
#include "Buff.h"
#include "Effect.h"
#include "Entity.h"
namespace effects {
    Buff::Buff(std::weak_ptr<Entity> entity, int numberOfTurns, std::map<size_t, int> modifier) : Effect(entity, modifier) {
        m_numberOfTurns = numberOfTurns;
    }

    int Buff::getRemainingTurns() {
        return m_numberOfTurns;
    }

    void Buff::turn() {
        --m_numberOfTurns;
        if (m_numberOfTurns <= 0) {
            endBattleTurn();
        }
    }

    void Buff::endBattleTurn() {
        std::shared_ptr<Entity> entity = m_entity.lock();
        if (entity) {
            (entity.get())->getEffects().erase(static_cast<std::shared_ptr<Effect>>(this));
        }
    }
}