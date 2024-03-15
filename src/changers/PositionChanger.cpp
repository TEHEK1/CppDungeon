//
// Created by Владимир Попов on 08.03.2024
//
#include "changers/PositionChanger.h"
#include "player/Player.h"

void changers::PositionChanger::setPosition(Player *player, Position newPosition){
    player->m_position = newPosition;
}