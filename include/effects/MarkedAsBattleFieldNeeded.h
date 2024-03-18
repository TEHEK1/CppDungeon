//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_MARKEDASBATTLEFIELDNEEDED_H
#define TEST_MARKEDASBATTLEFIELDNEEDED_H
#include <memory>
#include <functional>
#include "changers/BattleFieldChanger.h"
#include "changers/EffectChanger.h"
#include "namespaces/entity.h"
#include "BattleField.h"
namespace effects {
    class MarkedAsBattleFieldNeeded : public BattleFieldChanger {
        friend changers::EffectChanger;
    protected:
        virtual std::function<int(const std::shared_ptr<entity::Entity>&, const std::shared_ptr<BattleField> &)>
        getTurnFunctionBattleField() = 0;
    };
} // namespace effects
#endif //TEST_MARKEDASBATTLEFIELDNEEDED_H
