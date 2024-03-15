//
// Created by artem on 12.03.2024.
//
#include "effects/Buff.h"
#include "effects/Effect.h"
#include "entity/Entity.h"
namespace effects {
    Buff::Buff(entity::Entity* entity, int numberOfTurns, const std::map<size_t, int>& modifier) :
    Effect(entity, modifier), m_numberOfTurns(numberOfTurns){}

    int Buff::getRemainingTurns() {
        return m_numberOfTurns;
    }

    void Buff::turn() {
        --m_numberOfTurns;
        if (m_numberOfTurns < 0) {
            endBattleTurn();
        }
    }

    void Buff::endBattleTurn() {
        std::shared_ptr<entity::Entity> entity = m_entity.lock();
        if (entity) {
            removeEffect(entity, static_cast<std::shared_ptr<Effect>>(this));
        }
    }
}