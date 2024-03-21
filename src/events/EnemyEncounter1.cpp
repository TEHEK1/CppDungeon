//
// Created by Амир Кашапов on 21.03.2024.
//

#include "events/EnemyEncounter1.h"
#include "enemies/BrigandFusilier/BrigandFusilier.h"
#include "enemies/BrigandRaider/BrigandRaider.h"
#include "enemies/CultistAcolyte/CultistAcolyte.h"
namespace events {
    EnemyEncounter1::EnemyEncounter1():EnemyEncounter(
            {std::make_shared<enemies::BrigandRaider::BrigandRaider>(),
             std::make_shared<enemies::BrigandFusilier::BrigandFusilier>(),
             std::make_shared<enemies::CultistAcolyte::CultistAcolyte>()}, 2) {}
} // events