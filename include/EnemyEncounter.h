//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMYENCOUNTER_H
#define UNTITLED_ENEMYENCOUNTER_H
#include <Entity.h>
#include <Event.h>
#include <vector>
class Enemy;
class Player;
class EnemyEncounter:public Event{
public:
    EnemyEncounter();
    void turn(Player*, int index) override;
    std::vector<std::shared_ptr<Entity>> getEnemies();
    std::vector<std::vector<char>> draw() override;

private:
    void _enemyMove(Player*, std::shared_ptr<Entity>);
    int _start_enemies;
    int _start_heroes;
    std::vector<std::shared_ptr<Entity>> _enemies;
    std::vector<int> _priority;
    std::vector<std::vector<char>> draw();
};
#endif //UNTITLED_ENEMYENCOUNTER_H
