//
// Created by artem on 12.03.2024.
//
#include "effects/PermanentEffect.h"
#include "entity/Entity.h"
namespace effects {
    PermanentEffect::PermanentEffect(const std::map<int, int>& modifier) : m_modifier(modifier) {}
    std::map<int, int> PermanentEffect::getModifier() {
        return m_modifier;
    }
} //namespace effects