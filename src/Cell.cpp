//
// Created by kait on 3/8/24.
//
#include "Cell.h"
//#include "MoveLeft.h"
//#include "MoveRight.h"

void Cell::freeMoves(Player * player, int index) {
    /*m_indexes.insert(index);
    if (m_indexes.size() == getEvents().size()) {
        addAction(player, std::shared_ptr<Action>(new MoveLeft));
        addAction(player, std::shared_ptr<Action>(new MoveRight));
    }*/
}

char Cell::getLevel() {
    char a = '5';
    return a;
}

std::vector<std::shared_ptr<Event>> Cell::getEvents(){
    return m_events;
}
