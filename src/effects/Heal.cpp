//
// Created by artem on 13.03.2024.
//
#include "effects/Heal.h"
namespace effects {
    Heal::Heal(int heal) :
            ImmediateCharacteristicEffect(std::map<int, int>{{static_cast<int>(Characteristic::HP), heal}}){}
}