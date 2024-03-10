//
// Created by Арсений Бородулин on 10.03.2024.
//
#include "SquadChanger.h"
#include "Squad.h"

void SquadChanger::move(const std::shared_ptr<Squad>& squad, int index1, int index2) {
    if (index1 < 0 || index1 >= squad->squad.size()) { throw std::invalid_argument("index is out of range"); }
    if (index2 >= squad->squad.size())  { index2 = static_cast<int>(squad->squad.size()) - 1;}
    if (index2 < 0)                     { index2 = 0; }
    if (squad->squad[index2] == nullptr) {
        squad->squad[index2] = squad->squad[index1];
        squad->squad[index1] = nullptr;
        return;
    }
    if (index1 == index2) { return; }

    std::shared_ptr<Entity> tmp = squad->squad[index2];
    squad->squad[index2] = nullptr;
    int const move_to = index1 < index2 ? -1 : 1;
    int ptr = index2 + move_to;
    while (tmp != nullptr || ptr != index1) { // index(tmp) < ptr, just chainswap
        std::swap(tmp, squad->squad[ptr]);
        ptr += move_to;
    }
}
void SquadChanger::move(const std::shared_ptr<Squad>& squad, const std::shared_ptr<Entity>& entity, int index2) {
    for (int i = 0; i < squad->squad.size(); ++i) {
        if (squad->squad[i] == entity) {
            return SquadChanger::move(squad, i, index2);
        }
    }
    throw std::invalid_argument("entity is not in squad");
}
void SquadChanger::relativeMove(const std::shared_ptr<Squad>& squad, int index, int offset) {
    SquadChanger::move(squad, index, offset);
}
void SquadChanger::relativeMove(const std::shared_ptr<Squad>& squad, const std::shared_ptr<Entity>& entity, int offset) {
    SquadChanger::move(squad, entity, offset);
}
void SquadChanger::remove(const std::shared_ptr<Squad>& squad, int index) {
    if (index < 0 || index >= squad->squad.size()) { throw std::invalid_argument("index is out of range"); }
    squad->squad[index] = nullptr;
}
void SquadChanger::remove(const std::shared_ptr<Squad>& squad, const std::shared_ptr<Entity>& entity) {
    for (int i = 0; i < squad->squad.size(); ++i) {
        if (squad->squad[i] == entity) {
            squad->squad[i] = nullptr;
            return;
        }
    }
    throw std::invalid_argument("entity is not in squad");
}
void SquadChanger::add(const std::shared_ptr<Squad>& squad, std::shared_ptr<Entity>entity, int index) {
    if (index < 0 || index >= squad->squad.size()) { throw std::invalid_argument("index is out of range"); }
    if (squad->squad[index] == nullptr) {
        squad->squad[index] = std::move(entity);
        return;
    }
    throw std::invalid_argument("index is not empty");
}
void SquadChanger::add(const std::shared_ptr<Squad>& squad, std::shared_ptr<Entity> entity) {
    for (int i = 0; i < squad->squad.size(); ++i) {
        if (squad->squad[i] != nullptr) {
            squad->squad[i] = std::move(entity);
            return;
        }
    }
    throw std::length_error("squad is full!");
}