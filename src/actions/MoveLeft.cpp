//
// Created by kait on 3/12/24.
//
#include "actions/MoveLeft.h"
#include "navigation/Map.h"
#include "player/Player.h"

namespace actions {

    void MoveLeft::act(Player *player) {
        setPosition(player, player -> getMap() -> moveLeft(player->getPosition()));
        returnToDefault(player);
        std::shared_ptr<Cell> temp = player->getMap()->getCell(player->getPosition());
        temp->generateEvents();
        for(const auto& event:temp->getEvents()) {
            if(event) {
                event->turn(player);
            }
        }
    }

    std::string MoveLeft::getName() {
        return "Move Player left";
    }
}//namespace actions