#include "BattleField.h"
#include "changers/ActionsChanger.h"
#include "entity/Enemy.h"
#include "entity/MarkedAsAutoTurn.h"
#include "events/EnemyEncounter.h"
#include "entity/Hero.h"
#include "enemies/BrigandRaider/BrigandRaider.h"
#include "enemies/BrigandFusier/BrigandFusilier.h"
#include "enemies/CultistAcolyte/CultistAcolyte.h"
#include "navigation/Map.h"
#include "player/Player.h"
#include "actions/UseSkill.h"
#include "actions/UseItem.h"
#include "generators/NumberGenerator.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <cstdlib>

void entity::MarkedAsAutoTurn::autoTurn(std::shared_ptr<Player> player, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> self, int rank) {
    auto skills = self->getSkills();
    std::vector<std::shared_ptr<skillDesigns::Skill>> availableSkills;
    for (auto i: skills) {
        if (std::find(i->getAvaibleRank().begin(), i->getAvaibleRank().end(), rank) != i->getAvaibleRank().end()) {
            availableSkills.push_back(i);
        }
    }
    int num = generators::NumberGenerator::generate(0, availableSkills.size() - 1);
    auto skillToUse = availableSkills[num];
    int target = generators::NumberGenerator::generate(0, skillToUse->getAvaibleAllyTarget().size() + skillToUse->getAvaibleEnemyTarget().size() - 1);
    if (target < skillToUse->getAvaibleAllyTarget().size()) {
        skillToUse->use(battleField, self, {player->getSquad()->getEntities()[skillToUse->getAvaibleAllyTarget()[target]]});
    }
    else {
        target -= skillToUse->getAvaibleAllyTarget().size();
        skillToUse->use(battleField, self, {battleField->getEnemySquad(self)->getEntities()[skillToUse->getAvaibleEnemyTarget()[target]]});
    }
}