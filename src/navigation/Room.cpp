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
#include "navigation/Hall.h"
#include "events/EmptyCell.h"
#include "events/Trap.h"
#include "events/Chest.h"
#include "events/EnemyEncounter1.h"
#include "events/EnemyEncounter2.h"
#include "events/EnemyEncounter3.h"
#include "events/EmptyCell.h"
#include "events/BossEncounter.h"
#include <vector>
#include <random>
#include "events/NPCEncounter.h"
#include "player/Player.h"
#include "Main.h"
#include "generators/NumberGenerator.h"
void Room::generateEvents(Player* player){

    if(m_used){
        return;
    }
    m_used = true;
    int num = generators::NumberGenerator::generate(0, 4);
    switch (num) {
        case 0:
            m_events.push_back(std::make_shared<events::BossEncounter>());
            break;
        case 1:
            m_events.push_back(std::make_shared<events::EnemyEncounter1>());
            break;
        case 2:
            m_events.push_back(std::make_shared<events::EnemyEncounter2>());
            break;
        case 3:
            m_events.push_back(std::make_shared<events::EnemyEncounter3>());
        default:
            m_events.push_back(std::make_shared<events::EmptyCell>());
            break;
    }
    num = generators::NumberGenerator::generate(0, 3);
    switch (num) {
        case 0:
            m_events.push_back(std::make_shared<events::Chest>());
            break;
        case 1:
            m_events.push_back(std::make_shared<events::EmptyCell>());
            break;
        case 2:
            m_events.push_back(std::make_shared<events::NPCEncounter>());
            break;
        default:
            m_events.push_back(std::make_shared<events::Trap>());
            break;
    }
    m_events.push_back(std::make_shared<events::ChooseRoomEvent>());
}
