//
// Created by Амир Кашапов on 15.03.2024.
//
#include <iostream>
#include "effects/Effect.h"
#include "effects/Buff.h"
#include "effects/PassiveBuff.h"
#include "effects/AutoAction.h"
#include "effects/ImmediateEffect.h"
#include "entity/Entity.h"
#include "EffectTest.h"
using namespace entity;
using namespace effects;
int main(){
    auto objectPtr = std::shared_ptr<Entity>(new Entity({{long(Characteristic::maxHP), 100}, {long(Characteristic::HP), 100}}));
    auto effectPtr = std::shared_ptr<Effect>(new ImmediateEffect(3, {{long(Characteristic::HP), -30}}));
    EffectTest::addEffect(objectPtr, effectPtr);
    for(int i = 0;i<10;i++) {
        std::cout << objectPtr->get(long(Characteristic::HP)) << "\n";
        EffectTest::turnEffects(objectPtr);
    }
}
