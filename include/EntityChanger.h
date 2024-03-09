//
// Created by Владимир Попов on 09.03.2024.
//

#ifndef UNTITLED_ENTITYCHANGER_H
#define UNTITLED_ENTITYCHANGER_H
#include <set>
#include <memory>
#include "Entity.h"
class Entity;
class EntityChanger : protected Entity{
protected:
    void setAccuracyModifier(int value) { m_accuracyModifier = value > 0 ? value : 0; }
    void setCriticalDamageChance(int value) { m_criticalDamageChance = value > 0 ? value : 0; }
    void setDamage(int value) { m_damage = value > 0 ? value : 0; }
    void setDodge(int value) { m_dodge = value > 0 ? value : 0; }
    void setDefence(int value) { m_defence = value > 0 ? value : 0; }
    void setSpeed(int value) { m_speed = value > 0 ? value : 0; }
    void setHP(int value) { m_HP = value > m_maxHP ? m_maxHP : value; }
    void setMaxHP(int value) { m_maxHP = value; }
};
#endif //UNTITLED_ENTITYCHANGER_H