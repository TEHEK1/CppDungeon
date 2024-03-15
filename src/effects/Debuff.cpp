//
// Created by artem on 12.03.2024.
//
#include "effects/Debuff.h"
#include "effects/Effect.h"
#include "entity/Entity.h"

namespace effects {
    Debuff::Debuff(int numberOfTurns, std::map<size_t, int> modifier) : Disease(modifier) {
        m_numberOfTurns = numberOfTurns;
    }

    int Debuff::getRemainingTurns() {
        return m_numberOfTurns;
    }

    void Debuff::turn() {
        return [&m_numberOfTurns]()
        --m_numberOfTurns;
        if (m_numberOfTurns < 0) {
            endBattleTurn();
        }
    }

    void Debuff::endBattleTurn() {
        std::shared_ptr<Entity> entity = m_entity.lock();
        if (entity) {
            removeEffect(static_cast<std::shared_ptr<Entity>>(entity), static_cast<std::shared_ptr<Effect>>(this));
        }
    }
    std::function<int(entity::Entity)> Debuff::getTurnFunction() {
        m_numberOfTurns =2;
        auto s =  [m_numberOfTurns](entity::Entity object){return m_numberOfTurns;};
    }
    std::function<int(entity::Entity)> Debuff::getEndBattleTurnFunction(){
        return [](entity::Entity object){return 1;};
    }
}
