//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMYENCOUNTER_H
#define UNTITLED_ENEMYENCOUNTER_H
#include "Event.h"
#include <vector>
class Enemy;
class EnemyEncounter:public Event{
public:
    void turn() override;
    std::vector <Enemy*> getEnemies();
};
#endif //UNTITLED_ENEMYENCOUNTER_H
