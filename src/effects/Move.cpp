//
// Created by artem on 13.03.2024.
//
#include "events/BattleField.h"
#include "effects/Move.h"
namespace effects {
    Move::Move(int offset) : ImmediateEffect(std::map<int, int>{}), m_offset(offset) {}

    std::function<int()> Move::getTurnBattleFieldFunction() {}
}