//
// Created by artem on 13.03.2024.
//
#include "effects/ImmediateEffect.h"
namespace effects {
    ImmediateEffect::ImmediateEffect(const std::map<int, int>& turner) : AutoAction(0, std::map<int, int>{}, turner) {}
}