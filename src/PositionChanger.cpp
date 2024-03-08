//
// Created by Владимир Попов on 08.03.2024
//
#include "PositionChanger.h"
#include "Player.h"

void PositionChanger::setPosition(Player *player, Position newPosition){
    player->m_position = newPosition;
}