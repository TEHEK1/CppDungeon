//
// Created by Арсений Бородулин on 10.03.2024.
//

#include "BattleField.h"


BattleField::BattleField(
    std::shared_ptr<Squad>& ally,
    std::shared_ptr<Squad>& enemy
) : ally(ally), enemy(enemy) {}

std::vector<std::shared_ptr<Entity>> BattleField::getEntities() const {
    std::vector<std::shared_ptr<Entity>> allies = ally->getEntities();
    std::vector<std::shared_ptr<Entity>> const enemies = enemy->getEntities();
    std::reverse(allies.begin(), allies.end());
    allies.reserve(allies.size() + enemies.size());
    for (const auto& entity : enemies) {allies.push_back(entity);}
    return allies;
}

std::shared_ptr<Squad> BattleField::getSquad(std::shared_ptr<Entity>& target) const {
    std::shared_ptr<Squad> ans = nullptr;
    for (const auto& entity : ally->getEntities()) {
        if (entity == target) {
            ans = ally;
            break;
        }
    }
    for (const auto& entity : enemy->getEntities()) {
        if (entity == target || ans != nullptr) {
            throw std::logic_error("squads are corrupted, they have similar entity");
        }
        if (entity == target) {
            return enemy;
        }
    }
    return ans;
}

std::shared_ptr<Squad> BattleField::getEnemySquad(std::shared_ptr<Entity>& target) const {
    std::shared_ptr<Squad> const allySquad = getSquad(target);
    if (allySquad == ally) { return enemy;}
    else { return ally;}
}

bool BattleField::areAllies(std::shared_ptr<Entity> ent1, std::shared_ptr<Entity> ent2) const {
    std::shared_ptr<Squad> const ent1_squad = getSquad(ent1);
    std::shared_ptr<Squad> const ent2_squad = getSquad(ent2);
    if (ent1 == nullptr || ent2 == nullptr) { throw std::logic_error("one of entities is not in the squad"); }
    return ent1_squad == ent2_squad;
}

