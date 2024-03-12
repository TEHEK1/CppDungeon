//
// Created by Арсений Бородулин on 10.03.2024.
//

#ifndef CPPDUNGEON_BATTLEFIELD_H
#define CPPDUNGEON_BATTLEFIELD_H
#include "Squad.h"

class BattleField {
    std::shared_ptr<Squad> ally;
    std::shared_ptr<Squad> enemy;

    BattleField(std::shared_ptr<Squad>& ally, std::shared_ptr<Squad>& enemy);
    std::vector<std::shared_ptr<Entity>> getEntities() const;
    std::shared_ptr<Squad> getSquad(std::shared_ptr<Entity>& target) const;
    std::shared_ptr<Squad> getEnemySquad(std::shared_ptr<Entity>& target) const;
    bool areAllies(std::shared_ptr<Entity>, std::shared_ptr<Entity>) const;

    friend class BattleFieldChanger;
};

#endif //CPPDUNGEON_BATTLEFIELD_H
