//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_DISEASE_H
#define CPPDUNGEON_DISEASE_H
#include "Debuff.h"
namespace effects {
    class Disease: public Debuff {
    public:
        Disease(std::map<size_t, int> modifier);
        void turn();
        virtual void endBattleTurn();
    };
}
#endif //CPPDUNGEON_DISEASE_H
