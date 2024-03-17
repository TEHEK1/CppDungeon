//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_MARKEDASENDBATTLE_H
#define TEST_MARKEDASENDBATTLE_H
#include "functional"
#include "namespaces/changers.h"
namespace effects{
    class MarkedAsEndBattle{
        int m_numberOfBattles;
    protected:
        friend changers::EffectChanger;
        virtual std::function<int()> getEndBattleTurnFunction();
    public:
        MarkedAsEndBattle(int numberOfBattles);
        int getRemainingBattles();
        virtual ~MarkedAsEndBattle() = default;
    };
} // namespace effects
#endif //TEST_MARKEDASENDBATTLE_H
