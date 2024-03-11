//
// Created by kait on 3/11/24.
//
#include "Hall.h"
#include "EmptyCell.h"
#include "Chest.h"
#include <vector>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

void Hall::generateEvents() {
    int random1 = random(1,2);
    if(random1 == 1) {
        m_events.push_back(std::shared_ptr<Event>(new EmptyCell));
    }else{
        m_events.push_back(std::shared_ptr<Event>(new Chest));
    }
}