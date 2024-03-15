//
// Created by Амир Кашапов on 15.03.2024.
//

#include "changers/EffectChanger.h"
#include "effects/Effect.h"
void changers::EffectChanger::turnEffect(const std::shared_ptr<effects::Effect>& effect) {
    effect -> turn();
}
void changers::EffectChanger::endBattleTurnEffect(const std::shared_ptr<effects::Effect>& effect) {
    effect ->endBattleTurn();
}
entity::Entity* changers::EffectChanger::getEntity(const std::shared_ptr<effects::Effect>& effect) {
    return effect->m_entity;
}