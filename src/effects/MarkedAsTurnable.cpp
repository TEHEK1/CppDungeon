//
// Created by Амир Кашапов on 15.03.2024.
//
#include "effects/MarkedAsTurnable.h"
#include "entity/Entity.h"
#include <iostream>
effects::MarkedAsTurnable::MarkedAsTurnable(int numberOfTurns): m_numberOfTurns(numberOfTurns) {}
int effects::MarkedAsTurnable::getRemainingTurns() {
    return m_numberOfTurns;
}

std::function<int()> effects::MarkedAsTurnable::getTurnFunction() {
    return  [&numberOfTurns = this->m_numberOfTurns](){numberOfTurns--;
        return numberOfTurns;};
}