//
// Created by artem on 13.03.2024.
//
#include "effects/Heal.h"
#include "entity/Trick.h"
#include "random"
namespace effects {
    Heal::Heal(int heal) :
            ImmediateEffect(std::map<int, int>{{trick::hash("HP"), heal}}){}
}