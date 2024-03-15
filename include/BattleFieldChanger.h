//
// Created by Арсений Бородулин on 10.03.2024.
//

#ifndef CPPDUNGEON_BATTLEFIELDCHANGER_H
#define CPPDUNGEON_BATTLEFIELDCHANGER_H
#include <memory>
class BattleField;
class Entity;

class BattleFieldChanger {
protected:
    static void move(const std::shared_ptr<BattleField>& field, std::shared_ptr<Entity> entity, int index2);
    static void relativeMove(const std::shared_ptr<BattleField>& field, std::shared_ptr<Entity>entity, int offset);
    static void remove(const std::shared_ptr<BattleField>& field, std::shared_ptr<Entity>entity);
};

#endif //CPPDUNGEON_BATTLEFIELDCHANGER_H