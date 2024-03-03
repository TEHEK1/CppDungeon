//
// Created by Арсений Бородулин on 03.03.2024.
//
#include "EmptyCell.h"
#include "Player.h"
#include "Monitor.h"
#include "Map.h"

void EmptyCell::turn(Player* player, int index) {
    player->getMonitor()->draw();
    player->getMap()->getCell(player->getPosition())->freeMoves(player, index);
}

std::vector<std::vector<char>> Event::draw() {
    std::vector<std::vector<char>> sprite;
    sprite.push_back(std::vector<char>{'/',  '-', '-', '-', '-', '-', '\\'});
    sprite.push_back(std::vector<char>{'|',  'E', 'M', 'P', 'T', 'Y', '|' });
    sprite.push_back(std::vector<char>{'|',  'C', 'E', 'L', 'L', '-', '|' });
    sprite.push_back(std::vector<char>{'\\', '-', '-', '-', '-', '-', '/' });
    return sprite;
}