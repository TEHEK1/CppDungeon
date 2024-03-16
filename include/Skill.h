//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_SKILL_H
#define CPPDUNGEON_SKILL_H
#include <vector>
#include <memory>
#include "BattleFieldChanger.h"
class Entity;
class BattleField;
class Skill: public BattleFieldChanger{
public:
    virtual std::vector<int> getAvaibleRank();
    virtual std::vector<int> getAvaibleEnemyTarget();
    virtual std::vector<int> getAvaibleAllyTarget();
    virtual void use(std::vector<std::shared_ptr<BattleField>>, std::weak_ptr<Entity>, std::vector<std::weak_ptr<Entity>>) final;
    virtual std::string isUsable() final;
    std::string getName();
};
#endif //CPPDUNGEON_SKILL_H
