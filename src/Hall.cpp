//
// Created by kait on 3/11/24.
//
#include "Hall.h"
#include "EmptyCell.h"
#include "Chest.h"
#include <vector>

void Hall::generateEvents() {
    if(rand()%2) {
        m_events.push_back(std::shared_ptr<Event>(new EmptyCell));
    }else{
        m_events.push_back(std::shared_ptr<Event>(new Chest));
    }
}