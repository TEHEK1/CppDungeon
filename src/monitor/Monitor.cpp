//
// Created by neb_orion on 09.03.2024.
//

#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Map.h"
#include <iostream>
#include "BattleField.h"
Monitor::Monitor(std::shared_ptr<events::EnemyEncounter> enemyEncounter):m_enemyEncounter(enemyEncounter) {

}
void Monitor::draw(Player *player) {

    auto heroes = player->getSquad()->getEntities();
    auto enemies = m_enemyEncounter->getEnemies()->getEntities();
    for(int height = 0;height<20;height++){
        for(auto& i:heroes){
            auto currentLine = (i->draw())[height];
            for(auto& j:currentLine){
                std::cout<<j;
            }
            std::cout<<"  ";

        }
        for(auto& i:enemies){
            auto currentLine = (i->draw())[height];
            std::reverse(currentLine.begin(), currentLine.end());
            for(auto& j:currentLine){
                std::cout<<j;
            }
            std::cout<<"  ";
        }
        std::cout<<"\n";
    }
    for(auto& i:heroes){
        std::cout<<i->get(Characteristic::HP)<<"             ";

    }
    for(auto& i:enemies){
        std::cout<<i->get(Characteristic::HP)<<"             ";
    }

}