//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H
#include <vector>
#include <set>
#include "Effect.h"
#include "trick.h"
class Skill;
class Entity{
protected:
    int AccuracyModifier;
    int CriticalDamageChance;
    int Damage;
    int Dodge;
    int Defence;
    int Speed;
    int HP;

    std::set<std::shared_ptr<effects::Effect>> m_effects;
public:
    Entity(int accuracyModifier, int criticalDamagehance, int damage,
            int dodge, int defence, int speed, int HP);
    std::vector<Skill*> getSkills();
    std::vector<std::vector<char>> draw();
    int getSpeed();
    int getHP();
    std::set<std::shared_ptr<effects::Effect>> getEffects();
protected:
    int _accuracyModifier;
    int _criticalDamagehance;
    int _damage;
    int _dodge;
    int _defence;
    int _speed;
    int _HP;
};

enum class Characteristic {
    accuracyModifier = trick::hash("accuracyModifier"), dodge = trick::hash("dodge"), defence = trick::hash("defence"), speed = trick::hash("speed"), HP = trick::hash("HP"), maxHP = trick::hash("maxHP"), marked = trick::hash("marked"), turnable = trick::hash("turnable"), movable = trick::hash("movable"), enemyType = trick::hash("enemyType"), minDamage = trick::hash("minDamage"), maxDamage = trick::hash("maxDamage"), criticalDamageChance = trick::hash("criticalDamageChance")};
#endif //UNTITLED_ENTITY_H
