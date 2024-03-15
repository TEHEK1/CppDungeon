//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_STUN_H
#define CPPDUNGEON_STUN_H
#include <memory>
#include "Debuff.h"
namespace effects {
    class Stun: public Debuff{
    public:
        Stun(int numberOfTurns);
        int resistanceHash() override;
    };
}
#endif //CPPDUNGEON_STUN_H
