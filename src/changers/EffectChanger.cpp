//
// Created by Амир Кашапов on 15.03.2024.
//
#include "changers/EffectChanger.h"
#include "effects/Effect.h"
#include "entity/Entity.h"
#include "effects/ImmediateEffect.h"
#include "effects/MarkedAsEndBattle.h"
#include "effects/MarkedAsEndBattleEntityNeeded.h"
#include "effects/MarkAsEndBattleBattleFieldNeeded.h"
#include "effects/MarkedAsTurnable.h"
#include "effects/MarkedAsEntityNeeded.h"
#include "effects/MarkedAsBattleFieldNeeded.h"
void changers::EffectChanger::turnEffects(const std::shared_ptr<entity::Entity>& entity) {
    if(entity == nullptr){
        return;
    }
    auto& effects = entity->m_effects;
    for (auto effectIterator = effects.begin(); effectIterator != effects.end();)
    {
        if (turnEffect(entity, *effectIterator) < 0){
            effectIterator = effects.erase(effectIterator);
        }
        else {
            ++effectIterator;
        }
    }
}

void changers::EffectChanger::endBattleTurnEffects(const std::shared_ptr<entity::Entity>& entity) {
    if(entity == nullptr){
        return;
    }
    auto& effects = entity->m_effects;
    for (auto effectIterator = effects.begin(); effectIterator != effects.end();)
    {
        if (endBattleTurnEffect(entity, *effectIterator) < 0){
            effectIterator = effects.erase(effectIterator);
        }
        else {
            ++effectIterator;
        }
    }
}
int changers::EffectChanger::turnEffect(const std::shared_ptr<entity::Entity>& entity,
                                         const std::shared_ptr<effects::Effect>& effect) {
    if (entity!= nullptr && dynamic_cast<effects::MarkedAsEntityNeeded*>(effect.get()) != nullptr) {
        return dynamic_cast<effects::MarkedAsEntityNeeded*>(effect.get())->getTurnFunctionEntity()(entity);
    }
    else if (entity!= nullptr && dynamic_cast<effects::MarkedAsTurnable*>(effect.get()) != nullptr) {
        return dynamic_cast<effects::MarkedAsTurnable*>(effect.get())->getTurnFunction()();
    }
    else {
        return 0;
    }
}
int changers::EffectChanger::endBattleTurnEffect(const std::shared_ptr<entity::Entity>& entity,
                                                  const std::shared_ptr<effects::Effect>& effect) {
    if (entity!= nullptr && dynamic_cast<effects::MarkedAsEndBattleEntityNeeded*>(effect.get()) != nullptr) {
        return dynamic_cast<effects::MarkedAsEndBattleEntityNeeded*>(effect.get())->getEndBattleTurnFunctionEntity()(entity);
    }
    else if (entity!= nullptr && dynamic_cast<effects::MarkedAsEndBattle*>(effect.get()) != nullptr) {
        return dynamic_cast<effects::MarkedAsEndBattle*>(effect.get())->getEndBattleTurnFunction()();
    }
    else {
        return 0;
    }
}
void changers::EffectChanger::addEffect(const std::shared_ptr<entity::Entity>& entity,
                                        const std::shared_ptr<effects::Effect>& effect) {
    if (entity != nullptr && dynamic_cast<effects::ImmediateEffect*>(effect.get()) != nullptr) {
        turnEffect(entity, effect);
    }
    else if(entity != nullptr) {
        if()
        entity->m_effects.insert(effect);
    }
}

void changers::EffectChanger::removeEffect(const std::shared_ptr<entity::Entity>& entity,
                                           const std::shared_ptr<effects::Effect>& effect) {
    if(entity != nullptr) {
        entity->m_effects.erase(effect);
    }
}
