//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_FORCEMOVE_H
#define CPPDUNGEON_FORCEMOVE_H
#include "ImmediateEffect.h"
class BattleField;
namespace effects {
    class ForceMove: public ImmediateEffect {
        int m_offset;
        std::weak_ptr<BattleField> m_battleField;
    public:
        ForceMove(std::weak_ptr<Entity>, std::weak_ptr<BattleField>, int offset);
        void turn();
    };
}
#endif //CPPDUNGEON_FORCEMOVE_H
