//
// Created by Арсений Бородулин on 03.03.2024.
//
#include "ChooseRoomEvent.h"
#include "ChooseNextRoom.h"
#include "Map.h"
#include "Monitor.h"
#include "Player.h"


void ChooseRoomEvent::turn(Player *player, int index) {
    player->getMonitor()->draw();
    player->getMap()->getCell(player->getPosition())->freeMoves(player, index);
    for (int coords : player->getMap()->getNextRooms()) {
        this->addAction(
            player,
            std::move(std::shared_ptr<actions::ChooseNextRoom>(new actions::ChooseNextRoom(coords)))
        );
    }
}

std::vector<std::vector<char>> ChooseRoomEvent::draw() {
    std::vector<std::vector<char>> sprite;
    return sprite;
}