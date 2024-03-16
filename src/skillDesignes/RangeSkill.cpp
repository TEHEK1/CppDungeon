#include "RangeSkill.h"
#include <vector>
#include <memory>
#include <algorithm>

template <int Size>
std::string isDesignUsable(std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects) {
    std::string parentRet = UniqueSizedSkill<Size>::isDesignUsable(battleField, actor, objects);
    if (!parentRet.empty()) {
        return parentRet;
    }

    auto battleFieldVector = battleField->getEntities(); // std::vector<std::shared_ptr<Entity>>
    int prev_pos = -1;
    for (auto obj: objects) {
        int newPos = std::find(battleFieldVector.begin(), battleFieldVector.end(), obj) - battleFieldVector.begin();
        if (std::find(newPos < prev_pos) {
            return "Given objects must be in row on the BattleField";
        }
        prev_pos = newPos;
    }
}