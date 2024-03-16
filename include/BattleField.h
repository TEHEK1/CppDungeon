#ifndef CPPDUNGEON_BATTLEFIELD_H
#define CPPDUNGEON_BATTLEFIELD_H
#include <vector>
#include <memory>
class Entity;
class Squad;
class BattleField {
public:
    std::vector<std::shared_ptr<Entity>> getEntities();
    std::shared_ptr<Squad> getSquad(std::shared_ptr<Entity>);
};
#endif //CPPDUNGEON_BATTLEFIELD_H