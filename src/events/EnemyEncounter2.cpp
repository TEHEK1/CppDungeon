//
// Created by Амир Кашапов on 21.03.2024.
//

#include "events/EnemyEncounter2.h"
#include "enemies/RabidGnasher/RabidGnasher.h"
#include "enemies/SwineSlasher/SwineSlasher.h"
#include "enemies/Webber/Webber.h"
namespace events {
    EnemyEncounter2::EnemyEncounter2():EnemyEncounter(
            {std::make_shared<enemies::RabidGnasher::RabidGnasher>(),
             std::make_shared<enemies::SwineSlasher::SwineSlasher>(),
             std::make_shared<enemies::Webber::Webber>()}) {}
} // events