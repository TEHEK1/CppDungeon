//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H
#include <vector>
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
public:
    Entity(int accuracyModifier, int criticalDamagehance, int damage,
            int dodge, int defence, int speed, int HP);
    std::vector<Skill*> getSkills();
    std::vector<std::vector<char>> draw();
    int getHP();
    int getSpeed();
protected:
    int _accuracyModifier;
    int _criticalDamagehance;
    int _damage;
    int _dodge;
    int _defence;
    int _speed;
    int _HP;
};
#endif //UNTITLED_ENTITY_H
