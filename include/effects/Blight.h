//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_BLIGHT_H
#define CPPDUNGEON_BLIGHT_H
#include "effects/Bleed.h"
namespace effects{
    class Blight:public Bleed {
    public:
        Blight(int numberOfTurns, int HPturner);
    };
}

#endif //CPPDUNGEON_BLIGHT_H
