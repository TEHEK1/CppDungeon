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
    std::vector<Skill*> getSkills;
    std::vector<std::vector<char>> draw();
};
#endif //UNTITLED_ENTITY_H
