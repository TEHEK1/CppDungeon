//
// Created by kait on 3/12/24.
//
#include "MoveLeft.h"
#include "Map.h"
#include "Player.h"


void MoveLeft::act(Player * player) {
    setPosition(player, Map::moveLeft(player -> getPosition()));
    player -> getMap() -> getCell(player -> getPosition()) -> generateEvents();
    int i = 0; //хз что такое i
    player -> getMap() -> getCell(player -> getPosition()) -> getEvents()[i] -> turn(player, i);
    returnToDefault(player);
}