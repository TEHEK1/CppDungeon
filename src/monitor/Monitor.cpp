//
// Created by neb_orion on 09.03.2024.
//

#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Map.h"
#include <iostream>
Monitor::Monitor(std::shared_ptr<events::EnemyEncounter> enemyEncounter):m_enemyEncounter(enemyEncounter) {

}
void Monitor::draw(Player *player) {
    auto battleField = m_enemyEncounter->getBattleField();
    for(int height = 0;height<20;height++){
        for(auto i:battleField->getEntities()){
            for(auto& j:i->draw()[height]){
                std::cout<<j;
            }
            std::cout<<"  ";
        }
        std::cout<<"\n";
    }
}