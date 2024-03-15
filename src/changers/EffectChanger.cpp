//
// Created by Амир Кашапов on 15.03.2024.
//

#include "changers/EffectChanger.h"
#include "effects/Effect.h"
#include "entity/Entity.h"
#include "effects/ImmediateEffect.h"
void changers::EffectChanger::turnEffects(const std::shared_ptr<entity::Entity>& entity) {
    for (const auto& effect : entity->getEffects()) {
        turnEffect(entity, effect);
    }
}

void changers::EffectChanger::endBattleTurnEffects(const std::shared_ptr<entity::Entity>& entity) {
    for (const auto& effect : entity->getEffects()) {
        turnEffect(entity, effect);
    }
}
void changers::EffectChanger::turnEffect(const std::shared_ptr<entity::Entity>& entity,
                                         const std::shared_ptr<effects::Effect>& effect) {

}
void changers::EffectChanger::endBattleTurnEffect(const std::shared_ptr<entity::Entity>& entity,
                                                  const std::shared_ptr<effects::Effect>& effect) {
    effect->getEndBattleTurnFunction()(entity);
}
void changers::EffectChanger::addEffect(const std::shared_ptr<entity::Entity>& entity,
                                        const std::shared_ptr<effects::Effect>& effect) {
    entity->m_effects.insert(effect);
    if (dynamic_cast<effects::ImmediateEffect*>(effect.get()) != nullptr) {
        turnEffect(entity, effect);
    }
}

void changers::EffectChanger::removeEffect(const std::shared_ptr<entity::Entity>& entity,
                                           const std::shared_ptr<effects::Effect>& effect) {
    entity->m_effects.erase(effect);
}
