//
// Created by kait on 3/11/24.
//
#include "navigation/Hall.h"
#include "events/EmptyCell.h"
#include "events/Trap.h"
#include "events/Chest.h"
#include "events/EnemyEncounter.h"
#include <vector>
#include <random>
#include "events/NPCEncounter.h"
#include "player/Player.h"
#include "Main.h"
void Hall::generateEvents(Player* player) {
    if(m_used){
        return;
    }
    m_used = true;
    m_events.push_back(std::shared_ptr<events::Event>(player->getMain()->getEvent()));
    /*if(random(1,2) == 1) {//TODO: Change it to grabbing from Main fabric
        m_events.push_back(std::shared_ptr<events::Event>(new events::EmptyCell));
    }else{

    }*/
}
