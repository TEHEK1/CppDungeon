//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_SKILL_H
#define CPPDUNGEON_SKILL_H
#include <vector>
#include <string>
#include <memory>
#include "BattleFieldChanger.h"

class Entity;
class Effect;
class BattleField;
class Skill: public BattleFieldChanger{
public:
    virtual ~Skill() = default;
    virtual std::vector<int> getAvaibleRank();
    virtual std::vector<int> getAvaibleAllyTarget();
    virtual std::vector<int> getAvaibleEnemyTarget();
    virtual void use(std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects) final;
    virtual std::string isUsable(std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects) final;
    std::string getName();
protected:
    void unsafeUse(int isCrit, std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor , std::vector<std::weak_ptr<Entity>> objects);
    virtual void unsafeSelfUse(int isCrit, std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> object) = 0;
    virtual void unsafeTargetUse(int isCrit, std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor, std::weak_ptr<Entity> object) = 0;
    virtual std::string isImplementationUsable(std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects);
    virtual int missed(std::weak_ptr<Entity> actor) final;
    virtual int dodged(std::weak_ptr<Entity> actor) final;
    virtual int resisted(std::weak_ptr<Entity> object, size_t effectHash, int crit) final;
    virtual int crited(std::weak_ptr<Entity> actor) final;
    virtual void addEffect(std::weak_ptr<Entity> object, std::shared_ptr<Effect> effect, int crited) final;

    int m_accuracy;
    int m_criticalDamageChance;
    std::vector<int> m_avaibleRank;
    std::vector<int> m_avaibleAllyTarget;
    std::vector<int> m_avaibleEnemyTarget;
    std::string m_name;

    virtual std::string isDesignUsable(std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects);
};
#endif //CPPDUNGEON_SKILL_H
