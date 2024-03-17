#include <stdexcept>
#include <algorithm>
#include <random>
#include "BattleField.h"
#include "skillDesigns/Skill.h"
#include "player/Squad.h"
#include "entity/Entity.h"

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

void Skill::use(std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects) {
    std::string tryUse = isUsable(battleField, actor, objects);
    if (tryUse.empty()) {
        if (missed(actor) <= 0) {
            unsafeUse(crited(actor), battleField, actor, objects);
        }
    }
    else {
        throw std::runtime_error(tryUse);
    }
}

std::string Skill::isUsable(std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects) {
    std::string firstToRet = isDesignUsable(battleField, actor, objects);
    if (firstToRet.empty()) {
        return isImplementationUsable(battleField, actor, objects);
    }
    return firstToRet;
}

int Skill::missed(std::weak_ptr<Entity> actor) {
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<int> dist(0,100);
    return actor.lock()->get(Characteristic::accuracyModifier) + 100 - dist(rng);
}

int Skill::dodged(std::weak_ptr<Entity> actor) {
    return actor.lock()->dodged();
}

int Skill::resisted(std::weak_ptr<Entity> object, size_t effectHash, int crit) {
    if (crit < 0) {
        return object.lock()->resisted(effectHash);
    }
    return object.lock()->resisted(effectHash) - 20;
}

int Skill::crited(std::weak_ptr<Entity> actor) {
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<int> dist(0, 100);
    return actor.lock()->get(Characteristic::criticalDamageChance) + m_criticalDamageChance - dist(rng);
}

void Skill::unsafeUse(int isCrit, std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor , std::vector<std::weak_ptr<Entity>> objects) {
    unsafeSelfUse(isCrit, battleField, actor);
    for (auto obj: objects) {
        unsafeTargetUse(isCrit, battleField, actor, obj);
    }
}

std::string Skill::isDesignUsable(std::shared_ptr<BattleField> battleField, std::weak_ptr<Entity> actor, std::vector<std::weak_ptr<Entity>> objects) {
    std::shared_ptr<Entity> actorSharedPtr = actor.lock();
    try {
        battleField->getSquad(actorSharedPtr);
    }
    catch(const std::exception& e) {
        return "Some entity not on battleField";
    }

    for (auto obj: objects) {
        try {
            battleField->getSquad(obj.lock());
        }
        catch(const std::exception& e) {
            return "Some entity not on battleField";
        }
    }

    auto actorSquadVector = battleField->getSquad(actorSharedPtr)->getEntities(); // std::vector<std::shared_ptr<Entity>>
    if (std::find(m_avaibleRank.begin(), m_avaibleRank.end(), 
            std::find(actorSquadVector.begin(), actorSquadVector.end(), actorSharedPtr)) == m_avaibleRank.end()) {
        return "Can't act from this rank";
    }

    for (auto obj: objects) {
        if (std::find(actorSquadVector.begin(), actorSquadVector.end(), obj) == actorSquadVector.end()) {
            if (std::find(m_avaibleAllyTarget.begin(), m_avaibleAllyTarget.end(), obj) == m_avaibleAllyTarget.end()) {
                return "Can't act on some ally target";
            }
        }
        else {
            if (std::find(m_avaibleEnemyTarget.begin(), m_avaibleEnemyTarget.end(), obj) == m_avaibleEnemyTarget.end()) {
                return "Can't act on some enemy target";
            }
        }
    }

    return std::string();
}