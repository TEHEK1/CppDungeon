//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_DISEASE_H
#define CPPDUNGEON_DISEASE_H
#include "Effect.h"
namespace effects {
    class Disease: public Effect {
    public:
        Disease(std::map<size_t, int> modifier);
    protected:
        std::function<int(entity::Entity)> getTurnFunction() override;
        virtual std::function<int(entity::Entity)> getEndBattleTurnFunction() override;
    };
}
#endif //CPPDUNGEON_DISEASE_H
