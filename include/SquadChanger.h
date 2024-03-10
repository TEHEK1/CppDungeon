//
// Created by Арсений Бородулин on 10.03.2024.
//

#ifndef CPPDUNGEON_SQUADCHANGER_H
#define CPPDUNGEON_SQUADCHANGER_H

#include "Squad.h"

class SquadChanger {
public:
    static void move(const std::shared_ptr<Squad>&, int index1, int index2);
    static void move(const std::shared_ptr<Squad>&, const std::shared_ptr<Entity>&entity, int index2);
    static void relativeMove(const std::shared_ptr<Squad>&, int index, int offset);
    static void relativeMove(const std::shared_ptr<Squad>&, const std::shared_ptr<Entity>&entity, int offset);
    static void remove(const std::shared_ptr<Squad>&, int index);
    static void remove(const std::shared_ptr<Squad>& squad, const std::shared_ptr<Entity>&entity);
    static void add(const std::shared_ptr<Squad>& squad, std::shared_ptr<Entity>entity, int index);
    static void add(const std::shared_ptr<Squad>& squad, std::shared_ptr<Entity>entity);
};

#endif //CPPDUNGEON_SQUADCHANGER_H
