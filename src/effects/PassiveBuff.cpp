//
// Created by artem on 12.03.2024.
//
#include "effects/PassiveBuff.h"
#include "Entity.h"
namespace effects {
    PassiveBuff::PassiveBuff(std::weak_ptr<Entity> entity, int numberOfBattles, std::map<size_t, int> modifier): Buff(entity, 1, modifier) {
        m_numberOfBattles = numberOfBattles;
    }

    int PassiveBuff::getRemainingBattles() {
        return m_numberOfBattles;
    }

    void PassiveBuff::endBattleTurn() {
        --m_numberOfBattles;
        if (m_numberOfBattles < 0) {
            std::shared_ptr<Entity> entity = m_entity.lock();
            if (entity) {
                (entity.get())->getEffects().erase(static_cast<std::shared_ptr<Effect>>(this));
            }
        }
    }
}