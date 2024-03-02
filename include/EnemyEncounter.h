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
    void turn(Player*, int index) override;
    std::vector <std::unique_ptr<Enemy>> getEnemies();
    std::vector<std::vector<char>> draw() override;

private:
    std::vector<std::unique_ptr<Enemy>> _enemies;
    std::vector<int> _priority;
    int _start_heroes;
    int _start_enemies;
    void _enemy_move(Player*, std::unique_ptr<Enemy>);
};
#endif //UNTITLED_ENEMYENCOUNTER_H
