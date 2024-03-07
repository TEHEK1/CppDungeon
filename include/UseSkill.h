//
// Created by Амир Кашапов on 25.02.2024.
//

#ifndef CPPDUNGEON_USESKILL_H
#define CPPDUNGEON_USESKILL_H
#include "Action.h"
#include <vector>
#include <memory>
class Entity;
class Skill;
class UseSkill: public Action{
public:
    // UseSkill(Entity* actor, Skill* skill, std::vector<Entity*> entities);
    UseSkill(Entity* actor, Skill* skill, std::vector<std::unique_ptr<Entity>> entities);
    void act(Player*) override;
};
#endif //CPPDUNGEON_USESKILL_H
