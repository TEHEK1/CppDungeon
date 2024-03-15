//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_BATTLEFIELD_H
#define CPPDUNGEON_BATTLEFIELD_H
#include <memory>
class Squad;
class Entity;
class BattleField {
public:
    BattleField(std::shared_ptr<Squad>, std::shared_ptr<Squad>);
    static void relativeMove(std::shared_ptr<BattleField>, std::shared_ptr<Entity>entity, int offset);
    bool areAllies(std::shared_ptr<Entity>);
};
#endif //CPPDUNGEON_BATTLEFIELD_H
