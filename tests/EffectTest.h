//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_EFFECTTEST_H
#define TEST_EFFECTTEST_H
#include "changers/EffectChanger.h"
#include "changers/EntityChanger.h"
#include "entity/Entity.h"
#include "effects/Effect.h"
class EffectTest: public changers::EntityChanger{
public:
    using changers::EntityChanger::addEffect;
    using changers::EntityChanger::turnEffects;
    using changers::EntityChanger::removeEffect;
};


#endif //TEST_EFFECTTEST_H
