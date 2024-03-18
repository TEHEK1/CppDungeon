//
// Created by artem on 16.03.2024.
//
#include "Main.h"
#include "events/Event.h"
#include "events/Chest.h"
#include "events/ChooseRoomEvent.h"
#include "events/EmptyCell.h"
#include "events/Chest.h"
#include "events/Trap.h"
#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Map.h"
//#include "events/EnemyEncounter.h"
#include <random>

int Main::my_rand(size_t seed) { //TODO change on norm random function
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % m_eventFactory.getFactoryMap().size();
}

Main::Main() {
    m_eventFactory.add<events::Chest>(0);
    m_eventFactory.add<events::ChooseRoomEvent>(1);
    m_eventFactory.add<events::EmptyCell>(2);
    m_eventFactory.add<events::Trap>(3);
}

//void Main::Init() {
//    m_eventFactory.add<events::Chest>(0);
//    m_eventFactory.add<events::ChooseRoomEvent>(1);
//    m_eventFactory.add<events::EmptyCell>(2);
//    m_eventFactory.add<events::Trap>(3);
//    //m_eventFactory.add<events::EnemyEncounter>(4);
//}

void Main::setSeed(std::size_t needSeed) {
    m_seed = needSeed;
}

size_t Main::getSeed() {
    return m_seed;
}

events::Event* Main::getEvent() {
    int id = my_rand(getSeed());
    return m_eventFactory.create(id);
}

//Monitor *Main::getGame() {
//    Monitor monitor;
//    Player player;
//    Map map(m_seed);
//    return &monitor;
//}