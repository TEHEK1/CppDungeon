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
    if (dynamic_pointer_cast<effects::MarkedAsEntityNeeded>(effect) != nullptr) {
        return dynamic_pointer_cast<effects::MarkedAsEntityNeeded>(effect)->getTurnFunctionEntity()(entity);
    }
    else if (dynamic_pointer_cast<effects::MarkedAsTurnable>(effect) != nullptr) {
        return dynamic_pointer_cast<effects::MarkedAsTurnable>(effect)->getTurnFunction()();
    }
    else {
        return 0;
    }
}
int changers::EffectChanger::endBattleTurnEffect(const std::shared_ptr<entity::Entity>& entity,
                                                  const std::shared_ptr<effects::Effect>& effect) {
    if (dynamic_pointer_cast<effects::MarkedAsEndBattleEntityNeeded>(effect) != nullptr) {
        return dynamic_pointer_cast<effects::MarkedAsEndBattleEntityNeeded>(effect)->getEndBattleTurnFunctionEntity()(entity);
    }
    else if (dynamic_pointer_cast<effects::MarkedAsEndBattle>(effect) != nullptr) {
        return dynamic_pointer_cast<effects::MarkedAsEndBattle>(effect)->getEndBattleTurnFunction()();
    }
    else {
        return 0;
    }
}
void changers::EffectChanger::addEffect(const std::shared_ptr<entity::Entity>& entity,
                                        const std::shared_ptr<effects::Effect>& effect) {
    if (dynamic_pointer_cast<effects::ImmediateEffect>(effect) != nullptr) {
        turnEffect(entity, effect);
    }
    else {
        entity->m_effects.insert(effect);
    }
}

void changers::EffectChanger::removeEffect(const std::shared_ptr<entity::Entity>& entity,
                                           const std::shared_ptr<effects::Effect>& effect) {
    entity->m_effects.erase(effect);
}
