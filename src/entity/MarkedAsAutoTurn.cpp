#include "entity/MarkedAsAutoTurn.h"
void entity::MarkedAsAutoTurn::autoTurn(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> self, int rank) {
    auto skills = entity->getSkills();
    std::vector<std::shared_ptr<skillDesigns::Skill>> availableSkills;
    for (auto i: skills) {
        if (std::find(i->getAvaibleRank().begin(), i->getAvaibleRank().end(), rank) != i->getAvaibleRank().end()) {
            availableSkills.push_back();
        }
    }
    int num = generators::NumberGenerator::generate(0, availableSkills.size() - 1);
    auto skillToUse = availableSkills[num];
    int target = generators::NumberGenerator::generate(0, skillToUse->getAvaibleAllyTarget().size() + skillToUse->getAvaibleEnemyTarget().size() - 1)
    if (target < skillToUse->getAvaibleAllyTarget().size()) {
        skillToUse->use(battleField, entity, skillToUse->getAvaibleAllyTarget()[target]);
    }
    else {
        target -= skillToUse->getAvaibleAllyTarget().size();
        skillToUse->use(battleField, entity, skillToUse->getAvaibleEnemyTarget()[target]);
    }
}