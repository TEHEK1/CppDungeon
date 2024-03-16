//
// Created by Амир Кашапов on 16.03.2024.
//
#include "effects/ImmediateCharacteristicEffect.h"
#include "entity/Entity.h"
effects::ImmediateCharacteristicEffect::ImmediateCharacteristicEffect(std::map<int, int> turner):m_turner(turner) {}

std::function<int(const std::shared_ptr<entity::Entity> &)>
effects::ImmediateCharacteristicEffect::getTurnFunctionEntity() {
        return  [&turner = this->m_turner]
                (const std::shared_ptr<entity::Entity>& object){
            for(auto &characteristic:turner){
                set(object, characteristic.first, object->getReal(characteristic.first) + characteristic.second);
            }
            return -1;};
}