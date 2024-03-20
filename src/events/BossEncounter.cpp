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
    BossEncounter::BossEncounter() {
        std::vector<std::shared_ptr<entity::Entity>> tmpEnemies;
        int num = generators::NumberGenerator::generate(0, 2);
        switch (num) {
            case 0:
                tmpEnemies.push_back(std::make_shared<Bosses::GardenGuardian::GardenGuardian>());
                break;
            case 1:
                tmpEnemies.push_back(std::make_shared<Bosses::BloodFount::BloodFount>());
                break;
            default:
                tmpEnemies.push_back(std::make_shared<Bosses::StoneShield::StoneShield>());
                break;
        }

        m_enemies = std::shared_ptr<Squad>(new Squad(tmpEnemies));
        m_priority = {};
        m_isInBattle = true;
        m_lastToMove = nullptr;
        m_battleField = std::shared_ptr<BattleField>(new BattleField(m_enemies, m_enemies));
    }

    void BossEncounter::turn(Player *player) {
        EnemyEncounter::turn(player);
        if(!getIsInBattle() && _checkAlive(player->getSquad()->getEntities())){
            addAction(player, std::make_shared<actions::Win>());
        }
    }

} // events