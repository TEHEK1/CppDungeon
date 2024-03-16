//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_SKILL_H
#define CPPDUNGEON_SKILL_H
#include <vector>
#include <memory>
#include "BattleFieldChanger"

class Entity;
class BattleField;
class Skill: public BattleFieldChanger{
public:
    virtual ~Skill() = default;
    virtual std::vector<int> getAvaibleRank();
    virtual std::vector<int> getAvaibleAllyTarget();
    virtual std::vector<int> getAvaibleEnemyTarget();
    virtual void use(std::vector<std::shared_ptr<BattleField>> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects) final;
    virtual std::string isUsable() final;
    std::string getName();
protected:
    void unsafeUse(bool isCrit, std::vector<std::shared_ptr<BattleField>> battleField, std::weak_ptr<Entity> actor , std::vector<std::weak_ptr<Entity>> objects);
    void unsafeSelfUse(int isCrit, std::vector<std::shared_ptr<BattleField>> battleField, std::weak_ptr<Entity> object) = 0;
    void unsafeTargetUse(int isCrit, std::vector<std::shared_ptr<BattleField>> battleField, std::weak_ptr<Entity> actor, std::weak_ptr<Entity> object) = 0;
    virtual std::string isImplementationUsable(std::vector<std::shared_ptr<BattleField>> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects);
    int missed() final;
    int dodged(std::weak_ptr<Entity>) final;
    int resisted(std::weak_ptr<Entity>object, size_t effectHash, crited) final;
    int crited() final;
    void addEffect(std::weak_ptr<Entity> object, std::shared_ptr<Effect> effect, int crited) final;

    int m_accuracy;
    int m_criticalDamageChance;
    std::vector<int> m_avaibleRank;
    std::vector<int> m_avaibleAllyTarget;
    std::vector<int> m_avaibleEnemyTarget;
    std::string m_name;
private:
    virtual std::string isDesignUsable(std::vector<std::shared_ptr<BattleField>> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects);
};
#endif //CPPDUNGEON_SKILL_H
