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

            entity->m_characteristics[static_cast<int>(characteristic)] = std::max(0, value);
            break;
        case Characteristic::HP:

            int maxHP = entity->get(Characteristic::maxHP);
            entity->m_characteristics[static_cast<int>(characteristic)] = std::min(maxHP, std::max(0, value));
            break;
    }
}

void changers::EntityChanger::set(std::shared_ptr<entity::Entity> entity, int characteristic, int value) {
    set(entity, static_cast<Characteristic>(characteristic), value);
}

void changers::EntityChanger::addSkill(std::shared_ptr<entity::Entity> entity, std::shared_ptr<Skill> skill) {
    entity->m_skills.insert(skill);
}

void changers::EntityChanger::removeSkill(std::shared_ptr<entity::Entity> entity, std::shared_ptr<Skill> skill) {
    entity->m_skills.erase(skill);
}