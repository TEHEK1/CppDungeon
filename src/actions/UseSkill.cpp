//
// Created by kait on 3/19/24.
//
#include "actions/UseSkill.h"
#include "BattleField.h"
#include "Squad.h"
namespace actions{
    UseSkill::UseSkill(std::shared_ptr<skillDesigns::RangeSkill> skill, std::shared_ptr<BattleField> battleField,
                       std::shared_ptr<entity::Entity> actor, std::vector<std::shared_ptr<entity::Entity>> objects):
                       m_skill(skill), m_battleField(battleField), m_actor(actor), m_objects(objects){};

    void UseSkill::act(Player *) {
        m_skill -> use(m_battleField, m_actor, m_objects);
    }

    std::string UseSkill::getName() {
        std::string positions;
        for(auto i:m_objects){
            positions+=std::to_string(m_battleField->getSquad(i)->getIndex(i))+" ";
        }
        return "Use skill " + m_skill->getName() + " on " +
        (m_battleField->areAllies(m_actor, m_objects[0])?"allies":"enemies") + " on " + positions + "positions";
    }
} // namespace actions