//
// Created by Амир Кашапов on 16.03.2024.
//

#ifndef TEST_IMMEDIATECHARACTERISTICEFFECT_H
#define TEST_IMMEDIATECHARACTERISTICEFFECT_H
#include "effects/ImmediateEffect.h"
#include "changers/EntityChanger.h"
namespace effects {
    class ImmediateCharacteristicEffect:public ImmediateEffect, public changers::EntityChanger{
        std::map<int, int> m_turner;
    public:
        explicit ImmediateCharacteristicEffect(std::map<int ,int> turner);
        ~ImmediateCharacteristicEffect() override = default;
        std::function<int (const std::shared_ptr<entity::Entity> &)> getTurnFunctionEntity() override;
    };
} // namespace effects
#endif //TEST_IMMEDIATECHARACTERISTICEFFECT_H
