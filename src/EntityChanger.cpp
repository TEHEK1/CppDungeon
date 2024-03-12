//
// Created by Владимир Попов on 12.03.2024
//
#include "EntityChanger.h"

void EntityChanger::set(Characteristic characteristic, int value) {
    switch (characteristic) {
        case Characteristic::accuracyModifier:
        case Characteristic::criticalDamageChance :
        case Characteristic::minDamage:
        case Characteristic::maxDamage:
        case Characteristic::dodge:
        case Characteristic::defence:
        case Characteristic::speed:

            m_entity->m_characteristics[static_cast<size_t>(characteristic)] = std::max(0, value);
            break;
        case Characteristic::HP:

            int maxHP = m_entity->get(Characteristic::maxHP);
            m_entity->m_characteristics[static_cast<size_t>(characteristic)] = std::min(maxHP, std::max(0, value));
            break;
    }
}


void EntityChanger::turnEffects() {
    for (const auto& effect : m_entity->m_effects) {
        effect->turn();
    }
}

void EntityChanger::endBattleTurnEffects() {
    for (const auto& effect : m_entity->m_effects) {
        effect->endBattleTurn();
    }
}

void EntityChanger::addEffect(std::shared_ptr<Effect> effect) {
    m_entity->m_effects.insert(effect); 

    if (dynamic_cast<ImmediateEffect*>(effect.get()) != nullptr) {
        effect->turn();
    }
}

void EntityChanger::removeEffect(std::shared_ptr<Effect> effect) {
    m_entity->m_effects.erase(effect);
}

void EntityChanger::addSkill(std::shared_ptr<Skill> skill) {
    m_entity->m_skills.insert(skill);
}

void EntityChanger::removeSkill(std::shared_ptr<Skill> skill) {
    m_entity->m_skills.erase(skill);
}