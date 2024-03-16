//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_GUARD_H
#define CPPDUNGEON_GUARD_H
#include <memory>
#include "effects/Buff.h"
namespace effects {
    class Guard: public Buff {
    public:
        Guard(int numberOfTurns, int defenceModifier);
    };

}
#endif //CPPDUNGEON_GUARD_H
