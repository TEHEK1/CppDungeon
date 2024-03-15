//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_MARKASENDBATTLEBATTLEFIELDNEEDED_H
#define TEST_MARKASENDBATTLEBATTLEFIELDNEEDED_H
#include <functional>

#include "namespaces/changers.h"
#include "namespaces/entity.h"
#include "changers/BattleFieldChanger.h"

namespace effects {
    class MarkedAsEndBattleBattleFieldNeeded: public BattleFieldChanger {
        friend changers::EffectChanger;
    protected:
        virtual std::function<int(const std::shared_ptr<entity::Entity> &)> getEndBattleTurnFunctionBattleField() = 0;
    };
} // namespace effects
#endif //TEST_MARKASENDBATTLEBATTLEFIELDNEEDED_H
