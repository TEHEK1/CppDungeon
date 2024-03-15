//
// Created by artem on 13.03.2024.
//
#include "events/BattleField.h"
#include "effects/ForceMove.h"

namespace effects {
    ForceMove::ForceMove(std::weak_ptr<entity::Entity> entity, std::weak_ptr<BattleField> battleField, int offset) : ImmediateEffect(entity, std::map<size_t, int>{}, 0, 0) {
        m_battleField = battleField;
        m_offset = offset;
    }
    void ForceMove::turn() {
        (m_battleField.lock()).get()->areAllies(static_cast<std::shared_ptr<entity::Entity>>(m_entity));
        (m_battleField.lock()).get()->relativeMove(static_cast<std::shared_ptr<BattleField>>(m_battleField), static_cast<std::shared_ptr<entity::Entity>>(m_entity), m_offset);
    }
}