
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
    class Effect{
    public:
        virtual ~Effect() = default;
    };
}

#endif //CPPDUNGEON_EFFECT_H
