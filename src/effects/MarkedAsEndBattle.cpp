//
// Created by Амир Кашапов on 15.03.2024.
//
#include "effects/MarkedAsEndBattle.h"

effects::MarkedAsEndBattle::MarkedAsEndBattle(int numberOfBattles): m_numberOfBattles(numberOfBattles){}

int effects::MarkedAsEndBattle::getRemainingBattles() {
    return m_numberOfBattles;
}

std::function<int()> effects::MarkedAsEndBattle::getEndBattleTurnFunction() {
    return  [&numberOfBattles = this->m_numberOfBattles](){numberOfBattles--;
        return numberOfBattles;};
}