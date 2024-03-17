//
// Created by artem on 13.03.2024.
//
#include "effects/Damage.h"
#include "entity/Trick.h"
namespace effects {
    Damage::Damage(int damage) :
    ImmediateCharacteristicEffect(std::map<int, int>{{static_cast<int>(Characteristic::HP), std::min(-damage, 0)}}){}
}