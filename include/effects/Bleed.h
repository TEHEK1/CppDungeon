//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_BLEED_H
#define CPPDUNGEON_BLEED_H
#include "effects/AutoAction.h"
namespace effects {
    class Bleed:public AutoAction {
    public:
        Bleed(std::weak_ptr<entity::Entity>, int numberOfTurns, int HPturner, int crited, int critModifier = 150);
    };
}
#endif //CPPDUNGEON_BLEED_H
