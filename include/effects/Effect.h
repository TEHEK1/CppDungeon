//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_EFFECT_H
#define CPPDUNGEON_EFFECT_H

#include <map>
#include <memory>
#include "changers/EntityChanger.h"
//class EntityChanger;
class Entity;
class EnemyEncounter;
namespace effects {
    class Effect: public EntityChanger {
        std::map<std::size_t, int> m_modifier;
        friend EnemyEncounter;
    public:
        Effect(std::weak_ptr<Entity>, std::map<std::size_t, int>);
        std::map<std::size_t, int> getModifier();
    protected:
        virtual void turn() = 0;
        virtual void endBattle() = 0;
        std::weak_ptr<Entity> m_entity;
    };
}

#endif //CPPDUNGEON_EFFECT_H
