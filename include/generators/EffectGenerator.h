//
// Created by Амир Кашапов on 16.03.2024.
//

#ifndef UGABUGA_EFFECTGENERATOR_H
#define UGABUGA_EFFECTGENERATOR_H
#include "effects/Effect.h"
#include <memory>
namespace generators {
    class EffectGenerator {
        template<class effectType, typename ...Args>
        std::shared_ptr<effectType> generateImmediateCharacteristicEffect(int crited, int minCharacteristics, int maxCharacteristics, Args... args);
        template<class effectType, typename ...Args>
        std::shared_ptr<effectType> generateNumberOfTurnsEffect(int crited, int numberOfTurns, Args... args);
        template<class effectType, typename ...Args>
        std::shared_ptr<effectType> generateUncritedEffect(int crited, Args... args);
    };
} // namespace generators
#endif //UGABUGA_EFFECTGENERATOR_H
