//
// Created by Арсений Бородулин on 10.03.2024.
//
#include "Squad.h"

Squad::Squad(std::vector<std::shared_ptr<entity::Entity>> new_squad) : m_squad(std::move(new_squad)) {}
Squad::Squad(std::vector<std::shared_ptr<entity::Entity>> new_squad, int size) : Squad(std::move(new_squad)) {
    if (size < 0) { throw std::invalid_argument("size have to be positive"); }
    m_squad.resize(std::max(m_squad.size(), static_cast<unsigned long>(size)));
    std::fill(m_squad.end() - static_cast<int>(size), m_squad.end(), nullptr);
}
std::vector<std::shared_ptr<entity::Entity>> Squad::getEntities() const {
    return m_squad;
}
std::shared_ptr<entity::Entity> Squad::getEntity(int index) const {
    if (index < 0 || index >= m_squad.size()) { return nullptr;}
    return m_squad[index];
}


