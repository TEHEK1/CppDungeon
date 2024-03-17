//
// Created by artem on 15.03.2024.
//

#ifndef CPPDUNGEON_MAIN_H
#define CPPDUNGEON_MAIN_H
#include "memory"
#include "random"
#include <map>
#include <string>
class Monitor;
namespace events{class Event;};
namespace entity {class Entity;};
#include "eventfactory.h"

class Main {
    size_t m_seed = 1;
    std::map<size_t, std::string> m_map;
    ObjectFactory<events::Event, size_t> m_eventFactory;
    ObjectFactory<entity::Entity, size_t> m_entityFactory;
public:
    Main();
    int my_rand(size_t);

    void setSeed(std::size_t);
    std::size_t getSeed();
    Monitor* getGame();
    events::Event* getEvent();
    entity::Entity getEntity();
};
#endif //CPPDUNGEON_MAIN_H
