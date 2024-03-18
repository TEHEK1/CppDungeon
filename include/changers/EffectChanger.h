//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef CPPDUNGEON_EFFECTCHANGER_H
#define CPPDUNGEON_EFFECTCHANGER_H
#include <memory>
#include "namespaces/effects.h"
#include "namespaces/entity.h"
class BattleField;
namespace changers {
    class EffectChanger {
        static int turnEffect(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<effects::Effect>& effect, const std::shared_ptr<BattleField>& battlefield = nullptr);
        static int endBattleTurnEffect(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<effects::Effect>& effect, const std::shared_ptr<BattleField>& battlefield = nullptr);
    protected:
        static void turnEffects(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<BattleField>& battlefield = nullptr);
        static void endBattleTurnEffects(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<BattleField>& battlefield = nullptr);
        static void addEffect(const std::shared_ptr<entity::Entity>& entity, std::shared_ptr<effects::Effect> effect, const std::shared_ptr<BattleField>& battlefield = nullptr);
        static void removeEffect(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<effects::Effect>& effect);
    };
} // namespace changers

#endif //CPPDUNGEON_EFFECTCHANGER_H
