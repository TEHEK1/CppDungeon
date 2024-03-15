//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_BLEED_H
#define CPPDUNGEON_BLEED_H
#include "effects/AutoAction.h"
#include "effects/MarkedAsResistable.h"
namespace effects {
    class Bleed:public AutoAction, public MarkedAsResistable{
    public:
        Bleed(int numberOfTurns, int HPturner);
        int resistanceHash() override;
    };
}
#endif //CPPDUNGEON_BLEED_H
