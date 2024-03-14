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
    for (std::pair<int, int> cords : player->getMap()->getNextRooms()) {
        this->addAction(
            player,
            std::move(std::shared_ptr<ChooseNextRoom>(new ChooseNextRoom(cords)))
        );
    }
}

std::vector<std::vector<char>> ChooseRoomEvent::draw() {
    std::vector<std::vector<char>> sprite;
    return sprite;
}