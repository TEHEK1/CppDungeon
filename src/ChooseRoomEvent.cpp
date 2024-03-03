//
// Created by Арсений Бородулин on 03.03.2024.
//
#include "ChooseRoomEvent.h"
#include "Map.h"
#include "Player.h"
#include "monitor.h"

// todo: Ивент, позволяющий в комнате выбирать следующую комнату.
//      Дочерний от класса Event. Переопределяет:
//      addActions(Player*, ChooseRoom*) для всех доступных ChooseRoom (См класс Map, ChooseRoom)
//      Class ChooseRoom does not exist

void ChooseRoomEvent::turn(Player *player, int index) {
    player->getMonitor()->draw();
    player->getMap()->getCell(player->getPosition())->freeMoves(player, index);
//    for (auto event : )
}

std::vector<std::vector<char>> Event::draw() {
    std::vector<std::vector<char>> sprite;
    sprite.push_back(std::vector<char>{'/',  '-', '-', '-', '-', '-', '\\'});
    sprite.push_back(std::vector<char>{'|',  'C', 'R', 'O', 'O', 'M', '|' });
    sprite.push_back(std::vector<char>{'|',  'E', 'V', 'E', 'N', 'T', '|' });
    sprite.push_back(std::vector<char>{'\\', '-', '-', '-', '-', '-', '/' });
    return sprite;
}