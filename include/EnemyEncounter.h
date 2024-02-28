//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMYENCOUNTER_H
#define UNTITLED_ENEMYENCOUNTER_H
#include "Event.h"
#include <vector>
class Enemy;
class Player;
class EnemyEncounter:public Event{
public:
    EnemyEncounter();
    ~EnemyEncounter();
    void turn(Player*, int index) override;
    std::vector <Enemy*> getEnemies();
    std::vector<std::vector<char>> draw() override;

private:
    std::vector<Enemy*> _enemies;
};
#endif //UNTITLED_ENEMYENCOUNTER_H
