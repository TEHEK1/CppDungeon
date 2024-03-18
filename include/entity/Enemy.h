//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H
#include "entity/Entity.h"
#include "EnemyType.h"
#include "namespaces/skillDesigns.h"
namespace entity {
    class Enemy : public Entity {
    public:
        Enemy(std::string name, std::map<int, int> characteristics, std::set<std::shared_ptr<skillDesigns::Skill>> skills);
    };
} // namespace entity
#endif //UNTITLED_ENEMY_H
