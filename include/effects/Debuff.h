//
// Created by artem on 12.03.2024.
//

#ifndef CPPDUNGEON_DEBUFF_H
#define CPPDUNGEON_DEBUFF_H
#include "effects/Disease.h"
#include "changers/EntityChanger.h"
namespace effects {
    class Debuff: public Disease {
        int m_numberOfTurns;
    public:
        Debuff(int numberOfTurns, std::map<size_t, int> modifier);
        int getRemainingTurns();
    protected:
        std::function<int(entity::Entity)> getTurnFunction() override;
        virtual std::function<int(entity::Entity)> getEndBattleTurnFunction() override;
    };

}
#endif //CPPDUNGEON_DEBUFF_H
