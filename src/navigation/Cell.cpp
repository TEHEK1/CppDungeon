//
// Created by kait on 3/8/24.
//
#include "navigation/Cell.h"
#include "actions/MoveLeft.h"
#include "actions/MoveRight.h"
#include "events/EnemyEncounter.h"

void Cell::freeMoves(Player * player, events::Event* event) {
    m_endedEvents.insert(event);
    if (m_endedEvents.size() == getEvents().size()) {
        addUniqueAction(player, std::make_shared<actions::MoveLeft>());
        addUniqueAction(player, std::make_shared<actions::MoveRight>());
    }
}

void Cell::freeMoves(Player * player) {
    if (m_endedEvents.size() == getEvents().size()) {
        addUniqueAction(player, std::make_shared<actions::MoveLeft>());
        addUniqueAction(player, std::make_shared<actions::MoveRight>());
    }
}

char Cell::getLevel() {
    int level = 1;
    for(auto event:getEvents()){
        if(auto enemyEncounter = std::dynamic_pointer_cast<events::EnemyEncounter>(event)) {
            level = std::max(level, enemyEncounter->getLevel());
        }
    }
    return level;
}

std::vector<std::shared_ptr<events::Event>> Cell::getEvents(){
    return m_events;
}