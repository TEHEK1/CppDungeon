//
// Created by Арсений Бородулин on 10.03.2024.
//
#include "BattleFieldChanger.h"
#include "SquadChanger.h"

void BattleFieldChanger::move(const std::shared_ptr<BattleField>& field, std::shared_ptr<Entity> entity, int index2) {
    std::shared_ptr<Squad> const squad = field->getSquad(entity);
    if (squad == nullptr) { throw std::logic_error("entity is not on the field"); }
    SquadChanger::move(squad, entity, index2);
}

void BattleFieldChanger::relativeMove(const std::shared_ptr<BattleField>& field, std::shared_ptr<Entity> entity, int offset) {
    std::shared_ptr<Squad> const squad = field->getSquad(entity);
    if (squad == nullptr) { throw std::logic_error("entity is not on the field"); }
    SquadChanger::relativeMove(squad, entity, offset);
}

void BattleFieldChanger::remove(const std::shared_ptr<BattleField>& field, std::shared_ptr<Entity>entity) {
    std::shared_ptr<Squad> const squad = field->getSquad(entity);
    if (squad == nullptr) { throw std::logic_error("entity is not on the field"); }
    SquadChanger::remove(squad, entity);
}

void BattleFieldChanger::add(const std::shared_ptr<BattleField>& field, std::shared_ptr<Entity>entity, int index) {
    std::shared_ptr<Squad> const squad = field->getSquad(entity);
    if (squad != nullptr) { throw std::logic_error("entity is already on the field"); }
    SquadChanger::add(squad, entity, index);
}

void BattleFieldChanger::add(const std::shared_ptr<BattleField>& field, std::shared_ptr<Entity>entity) {
    std::shared_ptr<Squad> const squad = field->getSquad(entity);
    if (squad != nullptr) { throw std::logic_error("entity is already on the field"); }
    SquadChanger::add(squad, entity);
}

