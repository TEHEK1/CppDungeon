//
// Created by Амир Кашапов on 20.03.2024.
//

#include "events/BossEncounter.h"
#include "bosses/GardenGuardian/GardenGuardian.h"
#include "generators/NumberGenerator.h"
#include "actions/Win.h"
namespace events {
    BossEncounter::BossEncounter() {
        std::vector<std::shared_ptr<entity::Entity>> tmpEnemies;
        tmpEnemies.push_back(std::make_shared<Bosses::GardenGuardian::GardenGuardian>());
        m_enemies = std::shared_ptr<Squad>(new Squad(tmpEnemies));
        m_priority = {};
        m_isInBattle = true;
        m_lastToMove = nullptr;
        m_battleField = std::shared_ptr<BattleField>(new BattleField(m_enemies, m_enemies));
    }

    void BossEncounter::turn(Player *player) {
        EnemyEncounter::turn(player);
        if(!getIsInBattle()){
            addAction(player, std::make_shared<actions::Win>());
        }
    }

} // events