//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_EFFECTTEST_H
#define TEST_EFFECTTEST_H
#include "changers/EffectChanger.h"
#include "changers/EntityChanger.h"
#include "entity/Entity.h"
#include "effects/Effect.h"
class EffectTest: public changers::EffectChanger{
public:
    using changers::EffectChanger::addEffect;
    using changers::EffectChanger::turnEffects;
    using changers::EffectChanger::removeEffect;
    using changers::EffectChanger::endBattleTurnEffects;
};


#endif //TEST_EFFECTTEST_H
