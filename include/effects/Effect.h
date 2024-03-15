//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_EFFECT_H
#define CPPDUNGEON_EFFECT_H

#include <map>
#include <memory>
#include <functional>
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
        explicit Effect(const std::map<std::size_t, int>& modifier);
        std::map<std::size_t, int> getModifier();
    protected:
        virtual std::function<int(entity::Entity)> getTurnFunction() = 0;
        virtual std::function<int(entity::Entity)> getEndBattleTurnFunction() = 0;
    };
}

#endif //CPPDUNGEON_EFFECT_H
