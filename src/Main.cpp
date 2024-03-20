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
#include "entity/Entity.h"
#include "entity/Enemy.h"
#include "enemies/BrigandFusilier/BrigandFusilier.h"
#include "enemies/BrigandRaider/BrigandRaider.h"
#include "enemies/CultistAcolyte/CultistAcolyte.h"
#include "bosses/GardenGuardian/BloodFount.h"
#include "bosses/GardenGuardian/GardenGuardian.h"
#include "bosses/GardenGuardian/StoneShield.h"
#include "heroes/BountyHunter/BountyHunter.h"
#include "items/Absinthe.h"
#include "items/BloodiedNeckerchief.h"
#include "items/FortifyingGarlic.h"
#include "items/LickWounds.h"
//#include "events/EnemyEncounter.h"
#include <random>
int Main::my_rand_event(size_t seed) { //TODO change on norm random function
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % m_eventFactory.getFactoryMap().size();
}
int Main::my_rand_entity(size_t seed) { //TODO change on norm random function
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % m_entityFactory.getFactoryMap().size();
}
int Main::my_rand_item(size_t seed) { //TODO change on norm random function
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % m_itemsFactory.getFactoryMap().size();
}

Main::Main() {
    m_eventFactory.add<events::Chest>(0);
    //m_eventFactory.add<events::ChooseRoomEvent>(1);
    m_eventFactory.add<events::EmptyCell>(1);
    m_eventFactory.add<events::Trap>(2);
    m_entityFactory.add<enemies::BrigandFusilier::BrigandFusilier>(0);
    m_entityFactory.add<enemies::BrigandRaider::BrigandRaider>(1);
    m_entityFactory.add<enemies::CultistAcolyte::CultistAcolyte>(2);
    m_entityFactory.add<Bosses::BloodFount::BloodFount>(3);
    m_entityFactory.add<Bosses::GardenGuardian::GardenGuardian>(4);
    m_entityFactory.add<Bosses::StoneShield::StoneShield>(5);
    m_entityFactory.add<Heroes::BountyHunter::BountyHunter>(6);
    m_itemsFactory.add<items::Absinthe::Absinthe>(0);
    m_itemsFactory.add<items::BloodiedNeckerchief::BloodiedNeckerchief>(1);
    m_itemsFactory.add<items::FortifyingGarlic::FortifyingGarlic>(2);
    m_itemsFactory.add<items::LickWounds::LickWounds>(3);
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
    int id = my_rand_event(getSeed());
    return m_eventFactory.create(id);
}

entity::Entity* Main::getEntity() {
    int id = my_rand_entity(getSeed());
    return m_entityFactory.create(id);
}
items::Item* Main::getItem() {
    int id = my_rand_entity(getSeed());
    return m_itemsFactory.create(id);
}

Player *Main::getGame() {
    auto map = std::make_shared<Map>(12);
    auto monitor = std::make_shared<Monitor>();
    Player* player = new Player(map, monitor);
    return player;
}