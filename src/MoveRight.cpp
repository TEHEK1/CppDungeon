//
// Created by kait on 3/12/24.
//
#include "MoveRight.h"
#include "Map.h"
#include "Player.h"


void MoveRight::act(Player * player) {
    setPosition(player, Map::moveRight(player -> getPosition()));
    player -> getMap() -> getCell(player -> getPosition()) -> generateEvents();
    int i = 0; //хз что такое i
    player -> getMap() -> getCell(player -> getPosition()) -> getEvents()[i] -> turn(player, i);
    returnToDefault(player);
}
