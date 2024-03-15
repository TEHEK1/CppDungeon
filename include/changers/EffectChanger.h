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
    protected:
        static void turnEffect(const std::shared_ptr<effects::Effect>& effect);
        static void endBattleTurnEffect(const std::shared_ptr<effects::Effect>& effect);
        static std::weak_ptr<entity::Entity> getEntity(const std::shared_ptr<effects::Effect>& effect);
    };
} // namespace changers

#endif //CPPDUNGEON_EFFECTCHANGER_H
