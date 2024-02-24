//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMYENCOUNTER_H
#define UNTITLED_ENEMYENCOUNTER_H
#include "Event.h"
#include "Enemy.h"
#include <vector>
class EnemyEncounter:Event{
    std::vector<Enemy> enemies;
};
#endif //UNTITLED_ENEMYENCOUNTER_H
