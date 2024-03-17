//
// Created by Амир Кашапов on 16.03.2024.
//
#include "generators/EffectGenerator.h"
#include "generators/NumberGenerator.h"
template<class effectType, typename ...Args>
std::shared_ptr<effectType> generators::EffectGenerator::generateImmediateCharacteristicEffect(int crited, int minCharacteristics, int maxCharacteristics, Args... args) {
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
generators::EffectGenerator::generateNumberOfTurnsEffect(int crited, int numberOfTurns, Args... args) {
    if(crited>=0){
        return std::make_shared<effectType>(numberOfTurns, args...);
    }
    else{
        return std::make_shared<effectType>(numberOfTurns, args...);
    }
}

template<class effectType, typename ...Args>
std::shared_ptr<effectType>
generators::EffectGenerator::generateUncritedEffect(int crited, Args ...args) {
    if(crited>=0){
        return std::make_shared<effectType>(args...);
    }
    else{
        return std::make_shared<effectType>(args...);
    }
}