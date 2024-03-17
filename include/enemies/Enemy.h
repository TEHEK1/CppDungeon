//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H
#include "entity/Entity.h"
#include "EnemyType.h"

class Enemy:public entity::Entity{
    protected:
    Enemy(std::string name, std::map<int, int> characteristics) : Entity(name, characteristics) {}
};
#endif //UNTITLED_ENEMY_H
