//
// Created by kait on 3/19/24.
//
#include "actions/UseSkill.h"

namespace actions{
    UseSkill::UseSkill(std::shared_ptr<skillDesigns::RangeSkill> skill, std::shared_ptr<BattleField> battleField,
                       std::shared_ptr<entity::Entity> actor, std::vector<std::shared_ptr<entity::Entity>> objects):
                       m_skill(skill), m_battleField(battleField), m_actor(actor), m_objects(objects){};

    void UseSkill::act(Player *) {
        m_skill -> use(m_battleField, m_actor, m_objects);
    }
} // namespace actions