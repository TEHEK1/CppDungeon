//
// Created by Владимир Попов on 17.03.2024
//
#ifndef UNTITLED_ENEMYTYPE_H
#define UNTITLED_ENEMYTYPE_H
#include "./entity/Trick.h"

enum class EnemyType{
    Human = trick::hash("Human"),
    Beast = trick::hash("Beast"),
    Unholy = trick::hash("Unholy"),
    Stonework = trick::hash("Stonework"),
    Eldritch = trick::hash("Eldritch"),
    Bloodsucker = trick::hash("Bloodsucker"),
    Husk = trick::hash("Husk"),
    Unique = trick::hash("Unique"),
    Trivia = trick::hash("Trivia")
};
#endif //ENEMYTYPE_H