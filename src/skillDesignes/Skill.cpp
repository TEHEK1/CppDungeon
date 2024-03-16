#include <stdexcept>
#include "Skill.h"

std::vector<int> Skill::getAvaibleRank() {
    return m_avaibleRank;
}

std::vector<int> Skill::getAvaibleAllyTarget() {
    return m_avaibleAllyTarget;
}

std::vector<int> Skill::getAvaibleEnemyTarget() {
    return m_avaibleEnemyTarget;
}

std::string Skill::getName() {
    return m_name;
} 

void Skill::use(std::vector<std::shared_ptr<BattleField>> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects) {
    std::string tryUse = isUsable(battleField, actor, objects);
    if (tryUse.empty()) {
        if (missed <= 0) {
            unsafeUse(crited(), battleField, actor, objects);
        }
    }
    else {
        throw std::runtime_error(tryUse);
    }
}

void Skill::isUsable(std::vector<std::shared_ptr<BattleField>> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects) {
    std::string firstToRet = isDesignUsable(battleField, actor, objects);
    if (firstToRet.empty()) {
        return isImplementationUsable(battleField, actor, objects);
    }
    return firstToRet;
}
