//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_MOVE_H
#define CPPDUNGEON_MOVE_H
#include "ImmediateEffect.h"
class BattleField;
namespace effects {
    class Move: public ImmediateEffect {
        int m_offset;
        std::weak_ptr<BattleField> m_battleField;
    public:
        Move(std::weak_ptr<Entity>, std::weak_ptr<BattleField> battleField, int offset);
        void turn();
    };
}
#endif //CPPDUNGEON_MOVE_H
