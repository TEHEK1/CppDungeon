//
// Created by artem on 12.03.2024.
//
#include "effects/Effect.h"
namespace effects {
    Effect::Effect(std::weak_ptr<Entity> entity, std::map<std::size_t, int> modifier) {
        m_entity = entity;
        m_modifier = modifier;
    }

    std::map<size_t, int> Effect::getModifier() {
        return m_modifier;
    }
}