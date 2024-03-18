#include "skillDesigns/RangeSkill.h"
#include "skillDesigns/Skill.h"
#include "BattleField.h"
#include <vector>
#include <memory>
#include <algorithm>
namespace skillDesigns {
    RangeSkill::RangeSkill(int size, std::string name, std::vector<int> availableRank,
                           std::vector<int> availableAllyTarget,
                           std::vector<int> availableEnemyTarget, int accuracy, int criticalDamageChance) : m_size(
            size),
                                                                                                            Skill(name,
                                                                                                                  availableRank,
                                                                                                                  availableAllyTarget,
                                                                                                                  availableEnemyTarget,
                                                                                                                  accuracy,
                                                                                                                  criticalDamageChance) {}

    std::string
    RangeSkill::isDesignUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                               std::vector<std::shared_ptr<entity::Entity>> objects) {
        std::string parentRet = Skill::isDesignUsable(battleField, actor, objects);
        if (!parentRet.empty()) {
            return parentRet;
        }

        auto battleFieldVector = battleField->getEntities(); // std::vector<std::shared_ptr<Entity>>
        int prev_pos = -1;
        for (const auto &obj: objects) {
            int newPos = std::find(battleFieldVector.begin(), battleFieldVector.end(), obj) - battleFieldVector.begin();
            if (newPos < prev_pos) {
                return "Given objects must be in row on the BattleField";
            }
            prev_pos = newPos;
        }

        return std::string();
    }
} // namespace skillDesigns