//
// Created by Арсений Бородулин on 03.03.2024.
//
#include "events/ChooseRoomEvent.h"
#include "actions/ChooseNextRoom.h"
#include "navigation/Map.h"
#include "monitor/Monitor.h"
#include "player/Player.h"


void events::ChooseRoomEvent::turn(Player *player) {
    player->getMonitor()->draw();
    player->getMap()->getCell(player->getPosition())->freeMoves(player, std::shared_ptr<Event>(this));
    for (int coords : player->getMap()->getNextRooms()) {
        this->addAction(
            player,
            std::move(std::shared_ptr<actions::ChooseNextRoom>(new actions::ChooseNextRoom(coords)))
        );
    }
}

std::vector<std::vector<char>> events::ChooseRoomEvent::draw() {
    std::vector<std::vector<char>> sprite;
    return sprite;
}