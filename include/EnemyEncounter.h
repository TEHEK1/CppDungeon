//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMYENCOUNTER_H
#define UNTITLED_ENEMYENCOUNTER_H
#include "Event.h"
#include "Enemy.h"
#include <queue>
#include <vector>
class EnemyEncounter:public Event{
    std::vector<Enemy> enemies;
public:
    void turn();
};
#endif //UNTITLED_ENEMYENCOUNTER_H
