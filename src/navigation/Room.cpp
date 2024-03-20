//
// Created by kait on 3/11/24.
//
#include "navigation/Room.h"
#include "events/EmptyCell.h"
#include "events/ChooseRoomEvent.h"
#include "events/Chest.h"
#include "events/Trap.h"
#include "events/BossEncounter.h"
#include "events/EnemyEncounter.h"
#include "generators/NumberGenerator.h"
#include "events/NPCEncounter.h"
#include <vector>
#include "player/Player.h"
#include "Main.h"
void Room::generateEvents(Player* player){

    if(m_used){
        return;
    }
    m_used = true;
    /*while(true){
        auto event = std::shared_ptr<events::Event>(player->getMain()->getEvent());
        if(!std::dynamic_pointer_cast<events::EnemyEncounter>(event) &&
                !std::dynamic_pointer_cast<events::BossEncounter>(event)){
            m_events.push_back(event);
            break;
        }
    }
    while(true){
        auto event = std::shared_ptr<events::Event>(player->getMain()->getEvent());
        if(!std::dynamic_pointer_cast<events::Chest>(event) &&
           !std::dynamic_pointer_cast<events::Trap>(event) &&
                   !std::dynamic_pointer_cast<events::NPCEncounter>(event)){
            m_events.push_back(event);
            break;
        }
    }*/
    m_events.push_back(std::make_shared<events::ChooseRoomEvent>());
}
