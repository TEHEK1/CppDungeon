#include "enemies/BrigandFusier/BrigantFusier.h"
#include <memory>

BrigandFusier::BrigandFusier(): entity::Enemy("Brigand Fusilier", {
                {static_cast<int>(Characteristic::accuracyModifier), 100},
                {static_cast<int>(Characteristic::criticalDamageChance), 69}, 
                {static_cast<int>(Characteristic::defence), 0}, 
                {static_cast<int>(Characteristic::dodge), 8}, 
                {static_cast<int>(Characteristic::HP), 12}, 
                {static_cast<int>(Characteristic::marked), 0},
                {static_cast<int>(Characteristic::maxDamage), 4},
                {static_cast<int>(Characteristic::maxHP), 15},
                {static_cast<int>(Characteristic::minDamage), 0},
                {static_cast<int>(Characteristic::movable), 25},
                {static_cast<int>(Characteristic::speed), 6},
                {static_cast<int>(Characteristic::turnable), 0},
                {static_cast<int>(Resistances::Bleed), 20},
                {static_cast<int>(Resistances::Blight), 20},
                {static_cast<int>(Resistances::Debuff), 15},
                {static_cast<int>(Resistances::Move), 25},
                {static_cast<int>(Resistances::Stun), 25}},
                {std::shared_ptr<>()}) {}