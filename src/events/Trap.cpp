//
// Created by Амир Кашапов on 15.03.2024.
//
#include "generators/NumberGenerator.h"
#include "events/Trap.h"
#include "player/Player.h"
#include "events/Chest.h"
#include "actions/Use.h"
#include "navigation/Cell.h"
#include "navigation/Map.h"
#include <memory>
#include "monitor/Monitor.h"
#include "actions/Use.h"
#include "actions/DontUse.h"
#include "Squad.h"
#include "effects/Damage.h"

void events::Trap::turn(Player * player) {
//    player -> getMonitor() -> draw();
//    std::shared_ptr<events::UsableEvent> ptr_Use(dynamic_cast<events::UsableEvent*>(this));
//    if(m_used) {
//        addAction(player, std::shared_ptr<actions::Use>(new actions::Use(ptr_Use)));
//    }
//    addAction(player, std::shared_ptr<actions::DontUse>(new actions::DontUse(std::shared_ptr<Trap>(this))));
}

void events::Trap::dontUse(Player *player) {
//    static int random = generators::NumberGenerator::generate(m_range_dontUse_start, m_range_dontUse_finish);
//    std::vector<std::shared_ptr<entity::Entity>> entities = player -> getSquad() -> getEntities();
//    for(int i = 0; i < entities.size(); i++){
//        addEffect(entities[i], std::make_shared<effects::Damage>(random));
//    }
//    player -> getMap() -> getCell(player->getPosition())->freeMoves(player, std::shared_ptr<events::Event>(this));
}

void events::Trap::use(Player *player) {
    static bool once = true;
    if(once) {
        once = false;
        static int random = generators::NumberGenerator::generate(m_range_use_start, m_range_use_finish);
        std::vector<std::shared_ptr<entity::Entity>> entities = player->getSquad()->getEntities();
        for (int i = 0; i < entities.size(); i++) {
            addEffect(entities[i], std::make_shared<effects::Damage>(random));
        }
//    |      __0__      |
//    |     /     \     |
//    |    / 0 0 0 \    |
//    |   | 0     0 |   |
//    |   | 0     0 |   |
//    |   | 0     0 |   |
//    |   |  0 0 0  |   |
//    |    \-------/    |
//
//
//    |      __x__      |
//    |     /     \     |
//    |    / x   x \    |
//    |   |   x x   |   |
//    |   |    x    |   |
//    |   |   x x   |   |
//    |   |  x   x  |   |
//    |    \-------/    |
        m_drawing[6]  = {'|',' ',' ',' ',' ',' ',' ','_','_','x','_','_',' ',' ',' ',' ',' ',' ','|',' '};
        m_drawing[8]  = {'|',' ',' ',' ',' ','/',' ','x',' ',' ',' ','x',' ','\\',' ',' ',' ',' ','|',' '};
        m_drawing[9]  = {'|',' ',' ',' ','|',' ',' ',' ','x',' ','x',' ',' ',' ','|',' ',' ',' ','|',' '};
        m_drawing[10] = {'|',' ',' ',' ','|',' ',' ',' ',' ','x',' ',' ',' ',' ','|',' ',' ',' ','|',' '};
        m_drawing[11] = {'|',' ',' ',' ','|',' ',' ',' ','x',' ','x',' ',' ',' ','|',' ',' ',' ','|',' '};
        m_drawing[12] = {'|',' ',' ',' ','|',' ',' ','x',' ',' ',' ','x',' ',' ','|',' ',' ',' ','|',' '};
        player->getMap()->getCell(player->getPosition())->freeMoves(player, std::shared_ptr<events::Event>(this));
        m_used = false;
    }
}

std::vector<std::vector<char>> events::Trap::draw() {
    return m_drawing;
}