//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_MARKEDASTURNABLE_H
#define TEST_MARKEDASTURNABLE_H
#include "functional"
#include "namespaces/changers.h"
namespace effects{
    class MarkedAsTurnable{
        int m_numberOfTurns;
    protected:
        friend changers::EffectChanger;
        virtual std::function<int()> getTurnFunction();
    public:
        MarkedAsTurnable(int numberOfTurns);
        int getRemainingTurns();
        virtual ~MarkedAsTurnable() = default;
    };
} // namespace effects
#endif //TEST_MARKEDASTURNABLE_H
