//
// Created by artem on 12.03.2024.
//
#include "effects/PassiveDebuff.h"
#include "entity/Entity.h"
namespace effects {
    PassiveDebuff::PassiveDebuff(std::weak_ptr<entity::Entity> entity, int numberOfBattles, std::map<size_t, int> modifier): Debuff(entity, 1, modifier) {
        m_numberOfBattles = numberOfBattles;
    }

    int PassiveDebuff::getRemainingBattles() {
        return m_numberOfBattles;
    }

    void PassiveDebuff::endBattleTurn() {
        --m_numberOfBattles;
        if (m_numberOfBattles < 0) {
            std::shared_ptr<entity::Entity> entity = m_entity.lock();
            if (entity) {
                removeEffect(entity, static_cast<std::shared_ptr<Effect>>(this));
            }
        }
    }
}