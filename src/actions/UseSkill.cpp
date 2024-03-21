//
// Created by kait on 3/19/24.
//
#include "actions/UseSkill.h"
#include "BattleField.h"
#include "Squad.h"
#include "player/Player.h"
#include "navigation/Map.h"
#include "navigation/Cell.h"
#include "monitor/Monitor.h"
namespace actions{
    UseSkill::UseSkill(std::shared_ptr<skillDesigns::RangeSkill> skill, std::shared_ptr<BattleField> battleField,
                       std::shared_ptr<entity::Entity> actor, std::vector<std::shared_ptr<entity::Entity>> objects, std::vector<SquadIndexer> indexes):
                       m_skill(skill), m_battleField(battleField), m_actor(actor), m_objects(objects), m_indexes(indexes){};

    void UseSkill::act(Player *player) {
        auto returnedSkill = m_skill -> use(m_battleField, m_actor, m_objects);
        player->getMonitor()->setBuffer("used " + m_skill->getName() + " " + returnedSkill);

    }

    std::string UseSkill::getName() {
        std::string positions;
        for(auto i:m_indexes){
            positions+=std::to_string(i.index)+" ";
        }
        std::string answer = "Use skill " + m_skill->getName() ;
        if(m_indexes.size()>0){
          answer+=  " on ";
          if(m_indexes[0].type==SquadIndexer::Type::ally){answer+="allies";}
          else{answer+="enemies";}
          answer+=" on " + positions + "positions";
        }
        return answer;
    }
} // namespace actions