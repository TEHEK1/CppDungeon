//
// Created by Arseniy Borodulin on 10.03.2024.
//
#ifndef CPPDUNGEON_SQUAD_H
#define CPPDUNGEON_SQUAD_H

#include "Entity.h"

class Squad {
private:
    std::vector<std::shared_ptr<Entity>> squad;
public:
    explicit Squad(std::vector<std::shared_ptr<Entity>> new_squad);
    Squad(std::vector<std::shared_ptr<Entity>> new_squad, int size);
    std::vector<std::shared_ptr<Entity>> getEntities() const;
    std::shared_ptr<Entity> getEntity(int index) const;
    friend class SquadChanger;
};
#endif //CPPDUNGEON_SQUAD_H
