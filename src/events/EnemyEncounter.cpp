#include "BattleField.h"
#include "changers/ActionsChanger.h"
#include "entity/Enemy.h"
#include "events/EnemyEncounter.h"
#include "heroes/Hero.h"
#include "enemies/BrigandRaider/BrigandRaider.h"
#include "enemies/BrigandFusier/BrigandFusilier.h"
#include "enemies/CultistAcolyte/CultistAcolyte.h"
#include "navigation/Map.h"
// #include "monitor/Monitor.h"
#include "player/Player.h"
#include "actions/UseSkill.h"
#include "actions/UseItem.h"
#include "generators/NumberGenerator.h"
#include <memory>
#include <algorithm>
#include <cstdlib>

namespace events {
    EnemyEncounter::EnemyEncounter() {

        std::vector<std::shared_ptr<entity::Entity>> tmpEnemies;
        int numberOfEnemies = generators::NumberGenerator::generate(1, 3);
        tmpEnemies.resize(numberOfEnemies);

        for (auto &i: tmpEnemies) {
            int num = generators::NumberGenerator::generate(0, 2);
            switch (num)
            {
            case 0:
                i = std::make_shared<enemies::BrigandRaider::BrigandRaider>();
                break;
            case 1:
                i = std::make_shared<enemies::BrigandFusilier::BrigandFusilier>();
                break;
            default:
                i = std::make_shared<enemies::CultistAcolyte::CultistAcolyte>();
                break;
            }
        }

        m_enemies = Squad(tmpEnemies);
    }

    Squad EnemyEncounter::getEnemies() {
        return m_enemies;
    }

    std::vector<std::vector<char>> EnemyEncounter::draw() {
        std::vector<std::vector<char>> to_ret;
        for (auto &i: m_enemies.getEntities()) {
            to_ret.insert(to_ret.end(), i->draw().begin(), i->draw().end());
        }
        return to_ret;
    }

    void EnemyEncounter::turn(Player* player, std::shared_ptr<events::Event> index) {
        std::shared_ptr<BattleField> battleField = std::shared_ptr<BattleField>(new BattleField(player->getSquad(), std::make_shared<Squad>(m_enemies)));
        bool enemiesAlive = true;
        bool heroesAlive = true;
        for (auto i: player->getSquad()->getEntities()) {
            if (!i->isAlive()) {
                heroesAlive = false;
            }
        }
        for (auto i: m_enemies.getEntities()) {
            if (!i->isAlive()) {
                enemiesAlive = false;
            }
        }
        if (!(heroesAlive && enemiesAlive)) {
            for (auto i: player->getSquad()->getEntities()) {
                endBattleTurnEffects(i);
            }
            for (auto i: m_enemies.getEntities()) {
                endBattleTurnEffects(i);
            }
            player->getMap()->getCell(player->getPosition())->freeMoves(player, index);
        }
        std::vector<std::shared_ptr<entity::Entity>> priority = battleField->getEntities();
        std::sort(priority.begin(), priority.end(), [] (std::shared_ptr<entity::Entity> a, std::shared_ptr<entity::Entity> b) {
            a->get(Characteristic::speed) < b->get(Characteristic::speed);
        });
    }

}   