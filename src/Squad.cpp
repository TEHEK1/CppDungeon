//
// Created by Арсений Бородулин on 10.03.2024.
//
#include "Squad.h"

Squad::Squad(std::vector<std::shared_ptr<Entity>> new_squad) : squad(std::move(new_squad)) {}
Squad::Squad(std::vector<std::shared_ptr<Entity>> new_squad, int size) : Squad(std::move(new_squad)) {
    if (size < 0) { throw std::invalid_argument("size have to be positive"); }
    squad.resize(squad.size() + size);
    std::fill(squad.end() - static_cast<int>(size), squad.end(), nullptr);
}
std::vector<std::shared_ptr<Entity>> Squad::getEntities() const {
    return squad;
}
std::shared_ptr<Entity> Squad::getEntity(int index) const {
    if (index < 0 || index >= squad.size()) { throw std::invalid_argument("index is out of range"); }
    return squad[index];
}


