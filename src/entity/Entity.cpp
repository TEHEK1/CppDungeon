//
// Created by Владимир Попов on 09.03.2024
//
#include "entity/Entity.h"
#include "effects/Effect.h"
#include <random>
Entity::Entity(std::map<size_t, int> characteristics):m_characteristics(characteristics){}
std::vector<std::vector<char>> Entity::draw(){
    return {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '1', '1', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '1', '1', ' ', ' ', ' ', ' '},
        {' ', '1', '1', '1', '1', '1', '1', ' ', ' '}, 
        {' ', '1', ' ', '1', '1', ' ', '1', ' ', ' '}, 
        {' ', ' ', ' ', '1', '1', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', '1', '1', ' ', ' ', ' ', ' '}, 
        {' ', ' ', '1', ' ', ' ', '1', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
}

int Entity::get(std::size_t key) const {
    int result = 0;
    if (m_characteristics.count(key)){
        result = m_characteristics.at(key);
        for (const auto& effect : m_effects) {
            result += effect->getModifier()[key];
        }
    }
    return result;
}

int Entity::get(Characteristic characteristic) const {
    return get(static_cast<std::size_t>(characteristic));
}

const std::set<std::shared_ptr<effects::Effect>>& Entity::getEffects() const {
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

int Entity::dodged() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);
    return get(Characteristic::dodge) - dis(gen);
}

int Entity::resisted(std::size_t effectHash) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);
    return get(effectHash) - dis(gen);
}