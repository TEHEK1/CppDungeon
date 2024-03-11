#ifndef UNTITLED_SQUAD_H
#define UNTITLED_SQUAD_H
#include <vector>
#include <memory>
#include "Entity.h"

class SquadChanger;

class Squad {
    friend SquadChanger;
public:
    Squad(std::vector<std::shared_ptr<Entity>>);
    Squad(std::vector<std::shared_ptr<Entity>>, int);
    std::vector<std::shared_ptr<Entity>> getEntities();
    std::shared_ptr<Entity> getEntity(int);
};
#endif //UNTITLED_SQUAD_H