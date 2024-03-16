//
// Created by Амир Кашапов on 15.03.2024.
//
#include "generators/NumberGenerator.h"
#include "effects/Debuff.h"
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

void events::Trap::turn(Player * player) {
    player -> getMonitor() -> draw();
    std::shared_ptr<events::UsableEvent> ptr_Use(dynamic_cast<events::UsableEvent*>(this));
    addAction(player, std::shared_ptr<actions::Use>(new actions::Use(ptr_Use)));
    addAction(player, std::shared_ptr<actions::DontUse>(new actions::DontUse(std::shared_ptr<Trap>(this))));
}

void events::Trap::dontUse(Player *player) {
    int index = 1;
    player -> getMap() -> getCell(player -> getPosition()) -> freeMoves(player, index);
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