//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_MOVE_H
#define CPPDUNGEON_MOVE_H
#include "effects/ImmediateEffect.h"
#include "effects/MarkedAsBattleFieldNeeded.h"
class BattleField;
namespace effects {
    class Move: public ImmediateEffect, public MarkedAsBattleFieldNeeded {
        int m_offset;
    public:
        Move(int offset);
    };
}
#endif //CPPDUNGEON_MOVE_H
