//
// Created by artem on 13.03.2024.
//
#include "BattleField.h"
#include "effects/ForceMove.h"
#include "entity/Resistances.h"
namespace effects {
    ForceMove::ForceMove(int offset) : Move(offset) {}

    int ForceMove::resistanceHash() {
        return static_cast<int>(Resistances::Move);
    }
}