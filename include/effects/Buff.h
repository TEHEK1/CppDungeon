//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_BUFF_H
#define CPPDUNGEON_BUFF_H
#include "effects/PermanentEffect.h"
#include "changers/EntityChanger.h"
#include "effects/MarkedAsTurnable.h"
#include "effects/MarkedAsEndBattle.h"
namespace effects {
    class Buff: public PermanentEffect, public MarkedAsTurnable, public MarkedAsEndBattle{
    public:
        Buff(int numberOfTurns, const std::map<int, int>& modifier);
    };
}
#endif //CPPDUNGEON_BUFF_H
