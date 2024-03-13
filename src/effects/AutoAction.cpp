//
// Created by artem on 13.03.2024.
//
#include "effects/AutoAction.h"
#include "effects/Effect.h"
#include "Entity.h"
#include "EntityChanger.h"

namespace effects {
    AutoAction::AutoAction(std::weak_ptr<Entity> entity, int numberOfTurns, std::map<size_t, int> modifier,
                           std::map<size_t, int> turner, int crited, int critModifier): Effect(entity, modifier) {
        m_numberOfTurns = numberOfTurns;
        m_turner = turner;
        m_crited = crited;
        m_critModifier = critModifier;
    }
    int AutoAction::getRemainingTurns() {
        return m_numberOfTurns;
    }

    void AutoAction::turn() {
        --m_numberOfTurns;
        if (m_numberOfTurns < 0) {
            endBattleTurn();
        }
        for (auto i : m_turner) {
            set(i.first, i.second + m_entity.lock().get()->get(i.first));
        }
    }

    void AutoAction::endBattleTurn() {
        std::shared_ptr<Entity> p = static_cast<std::shared_ptr<Entity>>(m_entity);
        if (p) {
            (p.get())->getEffects().erase(static_cast<std::shared_ptr<Effect>>(this));
        }

    }
}