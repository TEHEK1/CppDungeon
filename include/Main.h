//
// Created by artem on 15.03.2024.
//

#ifndef CPPDUNGEON_MAIN_H
#define CPPDUNGEON_MAIN_H
#include "memory"
#include "random"
#include <map>
#include <string>
std::mt19937 rnd(time(0));
class Monitor;
namespace events{class Event;};
class Entity;
#include "eventfactory.h"
class Main {
    size_t m_seed = rnd() % 6;
    std::map<size_t, std::string> m_map;
    ObjectFactory<events::Event, size_t> m_eventFactory;
public:
    Main() {
        Init();
    }
    int my_rand(size_t);
    void Init();
    void setSeed(std::size_t);
    std::size_t getSeed();
    Monitor* getGame();
    events::Event* getEvent();
    Entity getEntity();
};
#endif //CPPDUNGEON_MAIN_H
