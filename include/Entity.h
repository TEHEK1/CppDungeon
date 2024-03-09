//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H
#include <set>
#include <memory>
class Skill;
class EntityChanger;
class Entity{
protected:
    int m_accuracyModifier;
    int m_criticalDamageChance;
    int m_damage;
    int m_dodge;
    int m_defence;
    int m_speed;
    int m_HP;
    int m_maxHP;

    friend class EntityChanger;
public:
    int getAccuracyModifier() const { return m_accuracyModifier; }
    int getCriticalDamageChance() const { return m_criticalDamageChance; }
    int getDamage() const { return m_damage; }
    int getDodge() const { return m_dodge; }
    int getDefence() const { return m_defence; }
    int getSpeed() const { return m_speed; }
    int getHP() const { return m_HP; }
    int getMaxHP() const { return m_maxHP; }

    std::set<std::shared_ptr<Skill>> getSkills() const;
    virtual bool isAlive() const final;
};
#endif //UNTITLED_ENTITY_H