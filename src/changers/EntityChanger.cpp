//
// Created by Владимир Попов on 12.03.2024
//
#include "entity/Entity.h"
#include "changers/EntityChanger.h"
#include "effects/Effect.h"
#include "effects/ImmediateEffect.h"

void changers::EntityChanger::set(std::shared_ptr<entity::Entity> entity, Characteristic characteristic, int value) {
    switch (characteristic) {
        case Characteristic::accuracyModifier:
        case Characteristic::criticalDamageChance :
        case Characteristic::minDamage:
        case Characteristic::maxDamage:
        case Characteristic::dodge:
        case Characteristic::defence:
        case Characteristic::speed:

            entity->m_characteristics[static_cast<size_t>(characteristic)] = std::max(0, value);
            break;
        case Characteristic::HP:

            int maxHP = entity->get(Characteristic::maxHP);
            entity->m_characteristics[static_cast<size_t>(characteristic)] = std::min(maxHP, std::max(0, value));
            break;
    }
}

void changers::EntityChanger::set(std::shared_ptr<entity::Entity> entity, size_t characteristic, int value) {
    set(entity, static_cast<Characteristic>(characteristic), value);
}

void changers::EntityChanger::turnEffects(std::shared_ptr<entity::Entity> entity) {
    for (const auto& effect : entity->m_effects) {
        turnEffect(effect);
    }
}

void changers::EntityChanger::endBattleTurnEffects(std::shared_ptr<entity::Entity> entity) {
    for (const auto& effect : entity->m_effects) {
        endBattleTurnEffect(effect);
    }
}

void changers::EntityChanger::addEffect(std::shared_ptr<entity::Entity> entity, std::shared_ptr<effects::Effect> effect) {
    entity->m_effects.insert(effect);

    if (dynamic_cast<effects::ImmediateEffect*>(effect.get()) != nullptr) {
        turnEffect(effect);
    }
}

void changers::EntityChanger::removeEffect(std::shared_ptr<entity::Entity> entity, std::shared_ptr<effects::Effect> effect) {
    entity->m_effects.erase(effect);
}

void changers::EntityChanger::addSkill(std::shared_ptr<entity::Entity> entity, std::shared_ptr<Skill> skill) {
    entity->m_skills.insert(skill);
}

void changers::EntityChanger::removeSkill(std::shared_ptr<entity::Entity> entity, std::shared_ptr<Skill> skill) {
    entity->m_skills.erase(skill);
}