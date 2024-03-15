//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_PERMANENTEFFECT_H
#define TEST_PERMANENTEFFECT_H
#include "Effect.h"
namespace effects {
    class PermanentEffect: public Effect {
        std::map<int, int> m_modifier;
        friend changers::EffectChanger;
    public:
        PermanentEffect(const std::map<int, int>& modifier);
        std::map<int, int> getModifier();
    };
} //namespace effects
#endif //TEST_PERMANENTEFFECT_H
