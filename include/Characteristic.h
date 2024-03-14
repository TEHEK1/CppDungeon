//
// Created by Владимир Попов on 12.03.2024 
//
#ifndef UNTITLED_CHARACTERISTIC_H
#define UNTITLED_CHARACTERISTIC_H

#include "Trick.h"

enum class Characteristic {
    accuracyModifier = trick::hash("accuracyModifier"),
    dodge = trick::hash("dodge"),
    defence = trick::hash("defence"),
    speed = trick::hash("speed"),
    HP = trick::hash("HP"),
    maxHP = trick::hash("maxHP"),
    marked = trick::hash("marked"),
    turnable = trick::hash("turnable"),
    movable = trick::hash("movable"),
    enemyType = trick::hash("enemyType"),
    minDamage = trick::hash("minDamage"),
    maxDamage = trick::hash("maxDamage"),
    criticalDamageChance = trick::hash("criticalDamageChance")
};

#endif //CHARACTERISTIC_H