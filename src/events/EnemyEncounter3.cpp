//
// Created by Амир Кашапов on 21.03.2024.
//

#include "events/EnemyEncounter3.h"
#include "enemies/CultistBrawler/CultistBrawler.h"
#include "enemies/Ghoul/Ghoul.h"
#include "enemies/PelagicGrouper/PelagicGrouper.h"
namespace events {
    EnemyEncounter3::EnemyEncounter3():EnemyEncounter(
            {std::make_shared<enemies::CultistBrawler::CultistBrawler>(),
             std::make_shared<enemies::Ghoul::Ghoul>(),
             std::make_shared<enemies::PelagicGrouper::PelagicGrouper>()}) {}
} // events