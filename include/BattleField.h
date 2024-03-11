#ifndef UNTITLED_BATTLEFIELD_H
#define UNTITLED_BATTLEFIELD_H
#include <vector>
#include <memory>

class Entity;
class Squad;
class BattleFieldChanger;

class BattleField {
    friend BattleField;
public:
    BattleField(std::shared_ptr<Squad>, std::shared_ptr<Squad>);
    std::vector<std::shared_ptr<Entity>> getEntities();
    std::shared_ptr<Squad> getSquad(std::shared_ptr<Entity>);
    bool areAllies(std::shared_ptr<Entity>, std::shared_ptr<Entity>);
};
#endif //UNTITLED_BATTLEFIELD_H