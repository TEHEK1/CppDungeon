//
// Created by kait on 3/12/24.
//
#include "actions/ChooseNextRoom.h"
#include "navigation/Map.h"
#include "player/Player.h"

namespace actions{
    ChooseNextRoom::ChooseNextRoom(char room):m_room(room) {}
    void ChooseNextRoom::act(Player * player) {
        setPosition(player, player -> getMap() -> chooseNextRoom(player ->getPosition(), m_room));
    }
} // namespace actions