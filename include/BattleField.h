//
// Created by Арсений Бородулин on 10.03.2024.
//

#ifndef CPPDUNGEON_BATTLEFIELD_H
#define CPPDUNGEON_BATTLEFIELD_H
#include "memory"
class Squad;
class Entity;

class BattleField {
private:
    std::shared_ptr<Squad> m_ally;
    std::shared_ptr<Squad> m_enemy;

public:
    BattleField(std::shared_ptr<Squad>& ally, std::shared_ptr<Squad>& enemy);
    std::vector<std::shared_ptr<Entity>> getEntities() const;
    std::shared_ptr<Squad> getSquad(std::shared_ptr<Entity>& target) const;
    std::shared_ptr<Squad> getEnemySquad(std::shared_ptr<Entity>& target) const;
    bool areAllies(std::shared_ptr<Entity> ent1, std::shared_ptr<Entity> ent2) const;

    friend class BattleFieldChanger;
};

#endif //CPPDUNGEON_BATTLEFIELD_H
