#include "BrigandRaider.h"
#include "EntityChanger.h"

enemies::BrigandRaider::BrigandRaider(){
    m_characteristics = {{static_cast<int>(Characteristic::accuracyModifier), 1}, 
    {static_cast<int>(Characteristic::dodge), 26},
    {static_cast<int>(Characteristic::defence), 25},
    {static_cast<int>(Characteristic::speed), 5},
    {static_cast<int>(Characteristic::HP), 25},
    {static_cast<int>(Characteristic::maxHP), 30},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::enemyType), 1}, // "1" it's type of Human;
    {static_cast<int>(Characteristic::minDamage), 4},
    {static_cast<int>(Characteristic::maxDamage), 15},
    {static_cast<int>(Characteristic::criticalDamageChance), 20},};
    
    m_resistances = {{static_cast<int>(Resistances::Stun), 73},
    {static_cast<int>(Resistances::Blight), 68},
    {static_cast<int>(Resistances::Bleed), 68},
    {static_cast<int>(Resistances::Debuff), 63},
    {static_cast<int>(Resistances::Move), 73},};
}