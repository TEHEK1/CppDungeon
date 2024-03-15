//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_EFFECT_H
#define CPPDUNGEON_EFFECT_H

#include <map>
#include <memory>
#include "changers/EntityChanger.h"
#include "namespaces/entity.h"
#include "namespaces/events.h"
#include "namespaces/changers.h"
namespace effects {
    class Effect: public changers::EntityChanger {
        std::map<std::size_t, int> m_modifier;
        friend changers::EffectChanger;
    public:
        virtual ~Effect() = default;
        Effect(std::weak_ptr<entity::Entity> entity, const std::map<std::size_t, int>& modifier);
        std::map<std::size_t, int> getModifier();
    protected:
        virtual void turn() = 0;
        virtual void endBattleTurn() = 0;
        std::weak_ptr<entity::Entity> m_entity;
    };
}

#endif //CPPDUNGEON_EFFECT_H
