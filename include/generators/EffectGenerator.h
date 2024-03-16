//
// Created by Амир Кашапов on 16.03.2024.
//

#ifndef UGABUGA_EFFECTGENERATOR_H
#define UGABUGA_EFFECTGENERATOR_H
#include "effects/Effect.h"
#include <memory>
namespace generators {
    class EffectGenerator {
        template<class effectType>
        std::shared_ptr<effectType> generateEffect(int minCharacteristics, int maxCharacteristics, int crited);
    };
} // namespace generators
#endif //UGABUGA_EFFECTGENERATOR_H
