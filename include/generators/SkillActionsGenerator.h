//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_SKILLACTIONSGENERATOR_H
#define UGABUGA_SKILLACTIONSGENERATOR_H
#include "actions/Action.h"
#include "actions/UseSkill.h"
#include "skillDesigns/RangeSkill.h"
#include <set>

namespace generators{
    class SkillActionsGenerator{
        std::set<std::shared_ptr<actions::UseSkill>> generateAvailableUseSkills(std::shared_ptr<skillDesigns::RangeSkill> skill,
                                                                                std::shared_ptr<BattleField> battleField,
                                                                                std::shared_ptr<entity::Entity> actor);
    };
}//namespace generators
#endif //UGABUGA_SKILLACTIONSGENERATOR_H
