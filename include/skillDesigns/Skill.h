//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_SKILL_H
#define CPPDUNGEON_SKILL_H
#include <vector>
namespace entity{
    class Entity;
} // namespace entity;
class Skill{
public:
    virtual ~Skill() = default;
    virtual void use(std::vector<entity::Entity*> objects);
};
#endif //CPPDUNGEON_SKILL_H
