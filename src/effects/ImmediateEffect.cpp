//
// Created by artem on 13.03.2024.
//
#include "effects/ImmediateEffect.h"
namespace effects {
    ImmediateEffect::ImmediateEffect(std::weak_ptr<Entity> entity, std::map<size_t, int> turner, int crited, int critModifier) : AutoAction(entity, 0, std::map<size_t, int>{}, turner, crited, critModifier) {

    }
}