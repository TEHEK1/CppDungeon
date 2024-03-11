//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMYENCOUNTER_H
#define UNTITLED_ENEMYENCOUNTER_H
#include "Entity.h"
#include "Event.h"
#include "Squad.h"
#include "SquadChanger.h"
#include <vector>
class Enemy;
class Player;
class EnemyEncounter:public Event, public SquadChanger{
public:
    EnemyEncounter();
    void turn(Player*, int index) override;
    Squad  getEnemies();
    std::vector<std::vector<char>> draw() override;

private:
    void _enemyMove(Player*, std::shared_ptr<Entity>);
    int m_start_enemies;
    int m_start_heroes;
    Squad  m_enemies;
    std::vector<int> m_priority;
};
#endif //UNTITLED_ENEMYENCOUNTER_H
