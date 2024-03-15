//
// Created by Амир Кашапов on 25.02.2024.
//

#ifndef CPPDUNGEON_USESKILL_H
#define CPPDUNGEON_USESKILL_H
#include "actions/Action.h"
#include <vector>
#include <memory>
class Entity;
class Skill;
class UseSkill: public actions::Action{
public:
    // UseSkill(Entity* actor, Skill* skill, std::vector<Entity*> entity);
    UseSkill(std::shared_ptr<Entity> actor, Skill* skill, std::vector<std::shared_ptr<Entity>> entities);
    void act(Player*) override;
};
#endif //CPPDUNGEON_USESKILL_H
