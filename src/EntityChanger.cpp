//
// Created by Владимир Попов on 12.03.2024
//
#include "EntityChanger.h"
#include "Effect.h"
#include "Entity.h"
#include <set>
#include "Characteristic.h"
#include "effects/ImmediateEffect.h"
#include <memory>
void EntityChanger::set(std::shared_ptr<Entity> entity, Characteristic characteristic, int value) {
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

void EntityChanger::set(std::shared_ptr<Entity> entity, size_t characteristic, int value) {
    set(entity, static_cast<Characteristic>(characteristic), value);
}

void EntityChanger::turnEffects(std::shared_ptr<Entity> entity) {
    for (const auto& effect : entity->m_effects) {
        effect->turn();
    }
}

void EntityChanger::endBattleTurnEffects(std::shared_ptr<Entity> entity) {
    for (const auto& effect : entity->m_effects) {
        effect->endBattleTurn();
    }
}

void EntityChanger::addEffect(std::shared_ptr<Entity> entity, std::shared_ptr<effects::Effect> effect) {
    entity->m_effects.insert(effect); 

    if (dynamic_cast<ImmediateEffect*>(effect.get()) != nullptr) {
        effect->turn();
    }
}

void EntityChanger::removeEffect(std::shared_ptr<Entity> entity, std::shared_ptr<effects::Effect> effect) {
    entity->m_effects.erase(effect);
}

void EntityChanger::addSkill(std::shared_ptr<Entity> entity, std::shared_ptr<Skill> skill) {
    entity->m_skills.insert(skill);
}

void EntityChanger::removeSkill(std::shared_ptr<Entity> entity, std::shared_ptr<Skill> skill) {
    entity->m_skills.erase(skill);
}