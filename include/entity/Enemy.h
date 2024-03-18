//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H
#include "entity/Entity.h"
#include "EnemyType.h"
namespace entity {
    class Enemy : public Entity {
    protected:
        Enemy(std::string name, std::map<int, int> characteristics) : Entity(name, characteristics) {}
    };
} // namespace entity
#endif //UNTITLED_ENEMY_H
