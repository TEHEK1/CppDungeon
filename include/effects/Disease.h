//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_DISEASE_H
#define CPPDUNGEON_DISEASE_H
#include "Effect.h"
#include "PermanentEffect.h"
#include "MarkedAsResistable.h"
namespace effects {
    class Disease: public PermanentEffect, public MarkedAsResistable{
    public:
        Disease(const std::map<int, int>& modifier);
        int resistanceHash() override;
    };
}
#endif //CPPDUNGEON_DISEASE_H
