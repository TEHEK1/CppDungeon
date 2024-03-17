#include "BrigandCutthroat.h"
#include "EntityChanger.h"

enemies::BrigandCutthroat::BrigandCutthroat(){
    m_characteristics = {{static_cast<int>(Characteristic::accuracyModifier), 1}, 
    {static_cast<int>(Characteristic::dodge), 3},
    {static_cast<int>(Characteristic::defence), 15},
    {static_cast<int>(Characteristic::speed), 3},
    {static_cast<int>(Characteristic::HP), 12},
    {static_cast<int>(Characteristic::maxHP), 15},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::enemyType), static_cast<int>(EnemyType::Human)},
    {static_cast<int>(Characteristic::minDamage), 3},
    {static_cast<int>(Characteristic::maxDamage), 5},
    {static_cast<int>(Characteristic::criticalDamageChance), 12}};
    
    m_resistances = {{static_cast<int>(Resistances::Stun), 25},
    {static_cast<int>(Resistances::Blight), 20},
    {static_cast<int>(Resistances::Bleed), 20},
    {static_cast<int>(Resistances::Debuff), 15},
    {static_cast<int>(Resistances::Move), 25}};
};