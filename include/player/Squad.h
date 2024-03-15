//
// Created by artem on 11.03.2024.
//

#ifndef CPPDUNGEON_SQUAD_H
#define CPPDUNGEON_SQUAD_H
#include <memory>
#include "entity/Entity.h"
#include "namespaces/entity.h"
class Squad {
    std::vector<std::shared_ptr<entity::Entity>> m_entities;
public:
    Squad(std::vector<std::shared_ptr<entity::Entity>>);
    std::vector<std::shared_ptr<entity::Entity>> getEntities();
};
#endif //CPPDUNGEON_SQUAD_H
