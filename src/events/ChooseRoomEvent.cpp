//
// Created by Арсений Бородулин on 03.03.2024.
//
#include "events/ChooseRoomEvent.h"
#include "actions/ChooseNextRoom.h"
#include "navigation/Map.h"
#include "monitor/Monitor.h"
#include "player/Player.h"


void events::ChooseRoomEvent::turn(Player *player) {
<<<<<<< HEAD
    player->getMonitor()->draw();
    player->getMap()->getCell(player->getPosition())->freeMoves(player, std::shared_ptr<Event>(this));
    for (int coords : player->getMap()->getNextRooms()) {
        this->addAction(
            player,
            std::move(std::shared_ptr<actions::ChooseNextRoom>(new actions::ChooseNextRoom(coords)))
        );
=======
    player->getMap()->getCell(player->getPosition())->freeMoves(player);
    player->getMonitor()->draw(player);
    player->getMap()->getCell(player->getPosition())->freeMoves(player, this);
    for (Position coords : player->getMap()->getNextRooms(player->getPosition())) {
        addUniqueAction(player, std::make_shared<actions::ChooseNextRoom>(coords));
>>>>>>> dev
    }
}

std::vector<std::vector<char>> events::ChooseRoomEvent::draw() {
    std::vector<std::vector<char>> sprite;
    return sprite;
}