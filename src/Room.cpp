//
// Created by kait on 3/11/24.
//
#include "Room.h"
#include "EmptyCell.h"
#include "ChooseRoomEvent.h"
#include "Chest.h"
#include <vector>

void Room::generateEvents(){
    if(rand()%2) {
        m_events.push_back(std::shared_ptr<Event>(new EmptyCell));
    }else{
        m_events.push_back(std::shared_ptr<Event>(new Chest));
    }
    if(rand()%2) {
        m_events.push_back(std::shared_ptr<Event>(new EmptyCell));
    }else{
        m_events.push_back(std::shared_ptr<Event>(new Chest));
    }
    m_events.push_back(std::shared_ptr<Event>(new ChooseRoomEvent));
}