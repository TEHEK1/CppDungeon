//
// Created by kait on 3/12/24.
//
#include "MoveRight.h"
#include "Map.h"
#include "Player.h"

namespace actions {

    void MoveRight::act(Player *player) {
        setPosition(player, player -> getMap() -> moveRight(player->getPosition()));
        Cell * temp = player->getMap()->getCell(player->getPosition());
        temp->generateEvents();
        for(int i = 0; i < temp->getEvents().size(); i++) {
            temp->getEvents()[i]->turn(player, i);
        }
        returnToDefault(player);
    }
}