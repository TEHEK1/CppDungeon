//
// Created by Амир Кашапов on 29.02.2024.
//

#ifndef CPPDUNGEON_SKILLSTORAGE_H
#define CPPDUNGEON_SKILLSTORAGE_H
enum class SkillId;
class Skill;
class SkillStorage{
public:
    Skill* getSkill(SkillId);
};
#endif //CPPDUNGEON_SKILLSTORAGE_H
