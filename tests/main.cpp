//
// Created by Амир Кашапов on 15.03.2024.
//
#include <iostream>
#include "effects/Effect.h"
#include "effects/Buff.h"
#include "effects/PassiveBuff.h"
#include "effects/AutoAction.h"
#include "effects/Damage.h"
#include "entity/Entity.h"
#include "EffectTest.h"
#include "effects/Heal.h"
using namespace entity;
using namespace effects;
int main(){
    auto objectPtr = std::shared_ptr<Entity>(new Entity({{long(Characteristic::maxHP), 100}, {long(Characteristic::HP), 100}}));
    auto effectPtr = std::shared_ptr<Effect>(new Damage(10));
    EffectTest::addEffect(objectPtr, effectPtr);
    std::cout << objectPtr->get(long(Characteristic::HP)) << "\n";
    EffectTest::addEffect(objectPtr, std::shared_ptr<Effect>(new Heal(20)));
    for(int i = 0;i<10;i++) {
        std::cout << objectPtr->get(long(Characteristic::HP)) << "\n";
        EffectTest::turnEffects(objectPtr);
    }
}
