//
// Created by artem on 12.03.2024.
//
#include "effects/Effect.h"

#include <utility>
namespace effects {
    Effect::Effect(const std::map<std::size_t, int>& modifier) : m_modifier(modifier) {}

    std::map<size_t, int> Effect::getModifier() {
        return m_modifier;
    }
}