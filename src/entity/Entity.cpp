//
// Created by Владимир Попов on 09.03.2024
//
#include "entity/Entity.h"
#include "effects/PermanentEffect.h"
#include <random>
entity::Entity::Entity(std::string name, std::map<int, int> characteristics):m_characteristics(characteristics){}

std::vector<std::vector<char>> entity::Entity::draw(){
    return isAlive() ? drawAlive() : drawDead();
}

std::vector<std::vector<char>> entity::Entity::drawDead(){
    return {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},        
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '.', ' ', ' ', '#', '%', '#', '#', '.', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '*', '#', '*', '#', '#', '#', '*', '+', '#', '.', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '.', '#', '#', '#', '%', '%', '%', '#', '#', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '%', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '.', ' ', ':', '#', '%', '@', '=', ':', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '.', '+', '#', '*', '#', '#', '%', '@', '@', '@', '@', '#', '=', '-', ' ', ' ', ' ', ' ', ' '},
        {' ', '=', '=', '*', '*', '*', '#', '%', '#', '%', '%', '%', '%', '#', '*', '+', '-', '.', ' ', ' '}
    };
}

                    
//            ..       
//       .  #%##.      
//       *#*###*+#.    
//      .###%%%###     
//         ##%#        
//      . :#%@=:       
//  .+#*##%@@@@#=-     
//  ==***#%#%%%%#*+-.  


int entity::Entity::get(int key) const {
    int result = 0;
    if (m_characteristics.find(key)!=m_characteristics.end()){
        result = m_characteristics.at(key);
        for (const auto& effect : m_effects) {
            auto permanentEffect = dynamic_cast<effects::PermanentEffect*>(effect.get());
            if(permanentEffect != nullptr)
            result += permanentEffect->getModifier()[key];
        }
    }
    return result;
}

int entity::Entity::get(Characteristic characteristic) const {
    return get(static_cast<int>(characteristic));
}

const std::set<std::shared_ptr<effects::Effect>>& entity::Entity::getEffects() const {
    return m_effects;
}

const std::set<std::shared_ptr<Skill>>& entity::Entity::getSkills() const {
    return m_skills;
}

std::string entity::Entity::getName() const {
    return m_name;
}

bool entity::Entity::isAlive() const {
    int currentHP = get(Characteristic::HP);
    return currentHP > 0;
}

bool entity::Entity::isTurnable() const {
    return get(Characteristic::turnable) >= 0;
}

int entity::Entity::dodged() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);
    return get(Characteristic::dodge) - dis(gen);
}

int entity::Entity::resisted(int effectHash) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);
    return get(effectHash) - dis(gen);
}

int entity::Entity::getReal(int key) const {
    return m_characteristics.contains(key) ? m_characteristics.at(key): 0;
}
