//
// Created by Владимир Попов on 09.03.2024
//
#include "Entity.h"
#include <random>

int Entity::get(std::size_t key) const {
    int result = m_characteristics.at(key);
    for (const auto& effect : m_effects) {
        result += effect->getModifier(key);
    }
    return result;
}

int Entity::get(Characteristic characteristic) const {
    if (characteristic == Characteristic::dodge) {
        if (get(Characteristic::turnable) < 0) {
            return 0;
        }
    }
    return get(static_cast<std::size_t>(characteristic));
}

const std::set<std::shared_ptr<Effect>>& Entity::getEffects() const {
    return m_effects;
}

const std::set<std::shared_ptr<Skill>>& Entity::getSkills() const {
    return m_skills;
}

std::string Entity::getName() const {
    return m_name;
}

bool Entity::isAlive() const {
    int currentHP = get(Characteristic::HP);
    return currentHP > 0;
}

bool Entity::isTurnable() const {
    return get(Characteristic::turnable) >= 0;
}

bool Entity::dodged() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);
    return dis(gen) < get(Characteristic::dodge);
}

bool Entity::resisted(std::size_t effectHash) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);
    return dis(gen) < get(effectHash);
}