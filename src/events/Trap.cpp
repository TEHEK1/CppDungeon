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
#include "player/Squad.h"
#include "effects/Damage.h"

void events::Trap::turn(Player * player) {
    player -> getMonitor() -> draw();
    std::shared_ptr<events::UsableEvent> ptr_Use(dynamic_cast<events::UsableEvent*>(this));
    if(m_isTrue) {
        addAction(player, std::shared_ptr<actions::Use>(new actions::Use(ptr_Use)));
    }
    addAction(player, std::shared_ptr<actions::DontUse>(new actions::DontUse(std::shared_ptr<Trap>(this))));
}

void events::Trap::dontUse(Player *player) {
    static int random = generators::NumberGenerator::generate(0, 2);
    std::vector<std::shared_ptr<entity::Entity>> entities = player -> getSquad() -> getEntities();
    for(int i = 0; i < entities.size(); i++){
        addEffect(entities[i], std::make_shared<effects::Damage>(random));
    }
    player -> getMap() -> getCell(player->getPosition())->freeMoves(player, std::shared_ptr<events::Event>(this));
}

void events::Trap::use(Player *player) {
    static int random = generators::NumberGenerator::generate(0, 3);
    std::vector<std::shared_ptr<entity::Entity>> entities = player -> getSquad() -> getEntities();
    for(int i = 0; i < entities.size(); i++){
        addEffect(entities[i], std::make_shared<effects::Damage>(random));
    }
    player -> getMap() -> getCell(player->getPosition())->freeMoves(player, std::shared_ptr<events::Event>(this));
    m_isTrue = false;
}

std::vector<std::vector<char>> events::Trap::draw(){
    //     -------
    //    |___-___|
    //    |__|_|__|
    //    |___-___|
    //     -------
    return {{' ', '-', '-', '-', '-', '-', '-', '-', ' ' },
            {'|', '_', '_', '_', '-', '_', '_', '_', '|' },
            {'|', '_', '_', '|', '-', '|', '_', '_', '|' },
            {'|', '_', '_', '_', '-', '_', '_', '_', '|' },
            {' ', '-', '-', '-', '-', '-', '-', '-', ' ' }};
}