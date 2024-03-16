//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef CPPDUNGEON_EFFECTCHANGER_H
#define CPPDUNGEON_EFFECTCHANGER_H
#include <memory>
#include "namespaces/effects.h"
#include "namespaces/entity.h"
namespace changers {
    class EffectChanger {
        static int turnEffect(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<effects::Effect>& effect);
        static int endBattleTurnEffect(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<effects::Effect>& effect);
    protected:
        static void turnEffects(const std::shared_ptr<entity::Entity>& entity);
        static void endBattleTurnEffects(const std::shared_ptr<entity::Entity>& entity);
        static void addEffect(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<effects::Effect>& effect);
        static void removeEffect(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<effects::Effect>& effect);
    };
} // namespace changers

#endif //CPPDUNGEON_EFFECTCHANGER_H
