//
// Created by artem on 11.03.2024.
//

#ifndef CPPDUNGEON_SQUAD_H
#define CPPDUNGEON_SQUAD_H
#include <memory>
#include "Entity.h"
class Entity;
class Squad {
    std::vector<std::shared_ptr<Entity>> m_entities;
public:
    Squad(std::vector<std::shared_ptr<Entity>>);
    std::vector<std::shared_ptr<Entity>> getEntities();
};
#endif //CPPDUNGEON_SQUAD_H
