//
// Created by Амир Кашапов on 20.03.2024.
//

#include "events/BossEncounter.h"
#include "bosses/GardenGuardian/GardenGuardian.h"
#include "generators/NumberGenerator.h"
#include "actions/Win.h"
#include "bosses/GardenGuardian/BloodFount.h"
#include "bosses/GardenGuardian/StoneShield.h"
namespace events {
    BossEncounter::BossEncounter(): EnemyEncounter(
            {std::make_shared<Bosses::StoneShield::StoneShield>(),
             std::make_shared<Bosses::GardenGuardian::GardenGuardian>(),
             std::make_shared<Bosses::BloodFount::BloodFount>(),
             }
            ) {
    }

    void BossEncounter::turn(Player *player) {
        EnemyEncounter::turn(player);
        if(!getIsInBattle() && _checkAlive(player->getSquad()->getEntities())){
            addAction(player, std::make_shared<actions::Win>());
        }
    }

} // events