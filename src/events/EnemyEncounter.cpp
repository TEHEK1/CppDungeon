#include "changers/ActionsChanger.h"
#include "entity/Enemy.h"
#include "events/EnemyEncounter.h"
#include "heroes/Hero.h"
#include "navigation/Map.h"
// #include "monitor/Monitor.h"
#include "player/Player.h"
#include "actions/UseSkill.h"
#include "actions/UseItem.h"
#include "generators/NumberGenerator.h"
#include <memory>
#include <cstdlib>

namespace events {
    EnemyEncounter::EnemyEncounter() {

        std::vector<std::shared_ptr<entity::Entity>> tmpEnemies;
        int numberOfEnemies = generators::NumberGenerator::generate(1, 3);
        tmpEnemies.resize(numberOfEnemies);
        entity::Enemy brigandFusilier = entity::Enemy("Brigand Fusilier", {
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
                {static_cast<int>(Resistances::Stun), 25},
            },);
        std::vector<entity::Entity> possibleEnemies = {};

        for (auto &i: tmpEnemies) {
            
        }

        m_enemies = Squad(tmpEnemies);
    }

    Squad EnemyEncounter::getEnemies() {
        return m_enemies;
    }

    // void EnemyEncounter::_enemyMove(Player* player, std::shared_ptr<Entity> enemy) {
    //     int max_rand_elem = enemy->getSkills().size();
    //     int move = (std::rand() % max_rand_elem);
    //     UseSkill(enemy, enemy->getSkills()[move], player->getHeroes()).act(player);
    // }

    // void EnemyEncounter::turn(Player *player) {
    //     int heroes_alive = 0;
    //     int enemies_alive = 0;

    //     for (auto &i: player->getHeroes()) {
    //         if (i->getHP() > 0) {
    //             ++heroes_alive;
    //         }
    //     }
    //     for (auto &i: getEnemies()) {
    //         if (i->getHP() > 0) {
    //             ++enemies_alive;
    //         }
    //     }
    //     if (heroes_alive == 0 || enemies_alive == 0) {
    //         player->getMap()->getCell(player->getPosition())->freeMoves(player, std::shared_ptr<Event>(this));
    //         player->getMonitor()->draw();
    //         return;
    //     }

    //     if (_priority.empty()) {
    //         _start_enemies = enemies_alive;
    //         _start_heroes = heroes_alive;
    //         _priority = std::vector<int>(_start_enemies + _start_heroes);
    //         for (int i = 0; i < _start_enemies + _start_heroes; ++i) {
    //             _priority[i] = i;
    //         }
    //         for (int i = 0; i < _start_enemies + _start_heroes; ++i) {
    //             for (int j = i + 1; j < _start_enemies + _start_heroes; ++j) {
    //                 bool first_is_hero = true;
    //                 bool second_is_hero = true;
    //                 int first_pos = i;
    //                 int second_pos = j;
    //                 if (_priority[i] >= _start_heroes) {
    //                     first_is_hero = false;
    //                     first_pos -= _start_heroes;
    //                 }
    //                 if (_priority[j] >= _start_heroes) {
    //                     second_is_hero = false;
    //                     second_pos -= _start_heroes;
    //                 }
    //                 if (first_is_hero && second_is_hero) {
    //                     if (player->getHeroes()[first_pos]->getSpeed() < player->getHeroes()[second_pos]->getSpeed()) {
    //                         std::swap(_priority[i], _priority[j]);
    //                     }
    //                 }
    //                 else if (first_is_hero && !second_is_hero) {
    //                     if (player->getHeroes()[first_pos]->getSpeed() <= _enemies[second_pos]->getSpeed()) {
    //                         std::swap(_priority[i], _priority[j]);
    //                     }
    //                 }
    //                 else if (!first_is_hero && second_is_hero) {
    //                     if (_enemies[first_pos]->getSpeed() < player->getHeroes()[second_pos]->getSpeed()) {
    //                         std::swap(_priority[i], _priority[j]);
    //                     }
    //                 }
    //                 else {
    //                     if (_enemies[first_pos]->getSpeed() < _enemies[second_pos]->getSpeed()) {
    //                         std::swap(_priority[i], _priority[j]);
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     while (!_priority.empty()) {
    //         int current_entity = _priority[0];
    //         _priority.erase(_priority.begin());
    //         if (current_entity < _start_heroes) {
    //             if (player->getHeroes()[current_entity]->getHP() > 0) {
    //                 for (auto skill: player->getHeroes()[current_entity]->getSkills()) {
    //                     addAction(player, std::move(std::shared_ptr<Action>(new UseSkill(player->getHeroes()[current_entity], skill, _enemies))));
    //                 }
    //                 for (auto item: player->getInventory().getItems()) {
    //                     addAction(player, std::move(std::shared_ptr<Action>(new UseItem(player, item, _enemies))));
    //                 }
    //                 return;
    //             }
    //             else {
    //                 continue;
    //             }
    //         }
    //         current_entity -= _start_heroes;
    //         if (_enemies[current_entity]->getHP() <= 0) {
    //             continue;
    //         }
    //         _enemyMove(player, _enemies[current_entity]);
    //     }
        
    //     player->getMonitor()->draw();
    // }

    std::vector<std::vector<char>> EnemyEncounter::draw() {
        std::vector<std::vector<char>> to_ret;
        for (auto &i: m_enemies.getEntities()) {
            to_ret.insert(to_ret.end(), i->draw().begin(), i->draw().end());
        }
        return to_ret;
    }
}