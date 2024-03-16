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

void Trap::turn(Player * player) {
    player -> getMonitor() -> draw();
    addAction(player, this->getActions());
}