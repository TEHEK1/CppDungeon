//
// Created by Владимир Попов on 09.03.2024
//
#include "Entity.h"

bool Entity::isAlive() const{
    return m_HP > 0 ? true : false;
}

// Realese getSkills ...