//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_MARKEDASBATTLEFIELDNEEDED_H
#define TEST_MARKEDASBATTLEFIELDNEEDED_H
#include <memory>
#include <functional>
#include "changers/BattleFieldChanger.h"
#include "namespaces/entity.h"
class MarkedAsBattleFieldNeeded: public BattleFieldChanger{
    virtual std::function<int(std::shared_ptr<entity::Entity>, std::shared_ptr<BattleField>)> getTurnBattleFieldFunction() = 0;
protected:
    virtual std::function<int(std::shared_ptr<entity::Entity>)>getTurnFunction() = delete;
};
#endif //TEST_MARKEDASBATTLEFIELDNEEDED_H
