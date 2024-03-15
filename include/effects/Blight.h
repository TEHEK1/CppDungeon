//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_BLIGHT_H
#define CPPDUNGEON_BLIGHT_H
#include "effects/AutoAction.h"
namespace effects{
    class Blight:public AutoAction {
    public:
        Blight(std::weak_ptr<entity::Entity>, int numberOfTurns, int HPturner, int crited, int critModifier = 150);
    };
}

#endif //CPPDUNGEON_BLIGHT_H
