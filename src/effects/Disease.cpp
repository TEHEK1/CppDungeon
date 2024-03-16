//
// Created by artem on 12.03.2024.
//
#include "effects/Disease.h"
#include "entity/Entity.h"
namespace effects {
    Disease::Disease(const std::map<int, int>& modifier) : PermanentEffect(modifier) {}
    int Disease::resistanceHash() {
        return static_cast<int>(Resistances::Debuff);
    }
}