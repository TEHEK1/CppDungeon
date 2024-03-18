//
// Created by Амир Кашапов on 16.03.2024.
//

#ifndef UGABUGA_EFFECTGENERATOR_H
#define UGABUGA_EFFECTGENERATOR_H
#include "effects/Effect.h"
#include "generators/NumberGenerator.h"
#include <memory>
namespace generators {
    class EffectGenerator {
    public:
        template<class effectType, typename ...Args>
        static std::shared_ptr<effectType> generateImmediateCharacteristicEffect(int crited, int minCharacteristics, int maxCharacteristics, Args... args);
        template<class effectType, typename ...Args>
        static std::shared_ptr<effectType> generateNumberOfTurnsEffect(int crited, int numberOfTurns, Args... args);
        template<class effectType, typename ...Args>
        static std::shared_ptr<effectType> generateUncritedEffect(int crited, Args... args);
    };
    template<class effectType, typename ...Args>
    std::shared_ptr<effectType> EffectGenerator::generateImmediateCharacteristicEffect(int crited, int minCharacteristics, int maxCharacteristics, Args... args) {
        if(crited>=0){
            return std::make_shared<effectType>(maxCharacteristics*150/100, args...);
        }
        else{
            int caracteristics = generators::NumberGenerator::generate(minCharacteristics, maxCharacteristics);
            return std::make_shared<effectType>(caracteristics);
        }
    }

    template<class effectType, typename ...Args>
    std::shared_ptr<effectType>
    EffectGenerator::generateNumberOfTurnsEffect(int crited, int numberOfTurns, Args... args) {
        if(crited>=0){
            return std::make_shared<effectType>(numberOfTurns * 150/100, args...);
        }
        else{
            return std::make_shared<effectType>(numberOfTurns, args...);
        }
    }

    template<class effectType, typename ...Args>
    std::shared_ptr<effectType>
    EffectGenerator::generateUncritedEffect(int crited, Args ...args) {
        if(crited>=0){
            return std::make_shared<effectType>(args...);
        }
        else{
            return std::make_shared<effectType>(args...);
        }
    }
} // namespace generators
#endif //UGABUGA_EFFECTGENERATOR_H
