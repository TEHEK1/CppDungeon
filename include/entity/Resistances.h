//
// Created by Владимир Попов on 12.03.2024 
//
#ifndef UNTITLED_RESISTANCES_H
#define UNTITLED_RESISTANCES_H

#include "entity/Trick.h"

enum class Resistances {
    Stun = trick::hash("Stun"),
    Blight = trick::hash("Blight"),
    Bleed = trick::hash("Bleed"),
    Debuff = trick::hash("Debuff"),
    Move = trick::hash("Move")
};

#endif //UNTITLED_RESISTANCES_H