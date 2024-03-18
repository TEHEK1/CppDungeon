//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_MONITOR_H
#define UNTITLED_MONITOR_H

// Non-selfmade library for UI realisation
// #include <ncurses.h>
#include <vector>
#include <memory>
#include "BattleField.h"
#include "events/EnemyEncounter.h"
class Player;
//       x --->
//  y
//  |
//  |
//  \/



//At this moment ncurses mode starts with initialistion of Monitor
class Monitor{
public:
    Monitor(std::shared_ptr<events::EnemyEncounter> );
    void draw(Player* player);//Ask draw functions realizations from Map, Entity and Event if needed
    std::shared_ptr<events::EnemyEncounter> m_enemyEncounter;
};
#endif //UNTITLED_MONITOR_H
