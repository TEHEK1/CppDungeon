//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_MARKEDASENDBATTLEENTITYNEEDED_H
#define TEST_MARKEDASENDBATTLEENTITYNEEDED_H
#include <functional>
#include "namespaces/changers.h"
#include "namespaces/entity.h"
namespace effects {
    class MarkedAsEndBattleEntityNeeded {
        friend changers::EffectChanger;
    protected:
        virtual std::function<int(const std::shared_ptr<entity::Entity> &)> getEndBattleTurnFunctionEntity() = 0;
    };
} // namespace effects
#endif //TEST_MARKEDASENDBATTLEENTITYNEEDED_H
