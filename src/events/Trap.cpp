//
// Created by Амир Кашапов on 15.03.2024.
//
#include "events/Trap.h"
#include "player/Player.h"
#include "events/Chest.h"
#include "actions/Use.h"
#include "navigation/Cell.h"
#include "navigation/Map.h"
#include "player/Item.h"
#include <memory>
#include "monitor/Monitor.h"
#include "actions/Use.h"
#include "actions/DontUse.h"

void Trap::turn(Player * player) {
    player -> getMonitor() -> draw();
    std::shared_ptr<events::UsableEvent> ptr_Use(dynamic_cast<events::UsableEvent*>(this));
    addAction(player, std::shared_ptr<actions::Use>(new actions::Use(ptr_Use)));
    addAction(player, std::shared_ptr<actions::DontUse>(new actions::DontUse(std::shared_ptr<Trap>(this))));
}

void Trap::dontUse(Player *player) {
    int index = 1;
    player -> getMap() -> getCell(player -> getPosition()) -> freeMoves(player, index);
}