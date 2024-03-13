//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_STUN_H
#define CPPDUNGEON_STUN_H
#include <memory>
#include "Debuff.h"
namespace effects {
    class Stun: public Debuff {
    public:
        Stun(std::weak_ptr<Entity>, int numberOfTurns);
    };
}
#endif //CPPDUNGEON_STUN_H
