#include "ActionsChanger.h"
#include "Enemy.h"
#include "EnemyEncounter.h"
#include "Hero.h"
#include "Map.h"
#include "Monitor.h"
#include "Player.h"
#include "UseSkill.h"
#include "UseItem.h"
#include <memory>
#include <cstdlib>

EnemyEncounter::EnemyEncounter() {
    int enemy_count = (std::rand() % 3) + 1;
    _enemies.resize(enemy_count);
    for (auto &i: _enemies) {
        int accuracyModifier = (std::rand() % 100) + 1;
        int criticalDamagehance = (std::rand() % 100) + 1;
        int damage = (std::rand() % 100) + 1;
        int dodge = (std::rand() % 100) + 1;
        int defence = (std::rand() % 100) + 1;
        int speed = (std::rand() % 100) + 1;
        int HP = (std::rand() % 100) + 1;

        i = std::unique_ptr<Enemy>{new Enemy(accuracyModifier,
                        criticalDamagehance,
                        damage,
                        dodge,
                        defence,
                        speed,
                        HP)};  
    }
}

std::vector<std::unique_ptr<Enemy>> EnemyEncounter::getEnemies() {
    return _enemies;
}

void EnemyEncounter::_enemy_move(Player *player, std::unique_ptr<Enemy> enemy) {
    int max_rand_elem = enemy->getSkills().size();
    int move = (std::rand() % max_rand_elem);
    UseSkill(enemy.release(), enemy->getSkills()[move], player->getHeroes()).act(player);
}

void EnemyEncounter::turn(Player *player, int index) {
    int heroes_alive = 0;
    int enemies_alive = 0;

    for (auto i: player->getHeroes()) {
        if (i->getHP() > 0) {
            ++heroes_alive;
        }
    }
    for (auto &i: getEnemies()) {
        if (i->getHP() > 0) {
            ++enemies_alive;
        }
    }
    if (heroes_alive == 0 || enemies_alive == 0) {
        player->getMap()->getCell(player->getPosition())->freeMoves(player, index);
        player->getMonitor()->draw();
        return;
    }

    if (_priority.empty()) {
        _start_enemies = enemies_alive;
        _start_heroes = heroes_alive;
        _priority = std::vector<int>(_start_enemies + _start_heroes);
        for (int i = 0; i < _start_enemies + _start_heroes; ++i) {
            _priority[i] = i;
        }
        for (int i = 0; i < _start_enemies + _start_heroes; ++i) {
            for (int j = i + 1; j < _start_enemies + _start_heroes; ++j) {
                bool first_is_hero = true;
                bool second_is_hero = true;
                int first_pos = i;
                int second_pos = j;
                if (_priority[i] >= _start_heroes) {
                    first_is_hero = false;
                    first_pos -= _start_heroes;
                }
                if (_priority[j] >= _start_heroes) {
                    second_is_hero = false;
                    second_pos -= _start_heroes;
                }
                if (first_is_hero && second_is_hero) {
                    if (player->getHeroes()[first_pos]->getSpeed() < player->getHeroes()[second_pos]->getSpeed()) {
                        std::swap(_priority[i], _priority[j]);
                    }
                }
                else if (first_is_hero && !second_is_hero) {
                    if (player->getHeroes()[first_pos]->getSpeed() <= _enemies[second_pos]->getSpeed()) {
                        std::swap(_priority[i], _priority[j]);
                    }
                }
                else if (!first_is_hero && second_is_hero) {
                    if (_enemies[first_pos]->getSpeed() < player->getHeroes()[second_pos]->getSpeed()) {
                        std::swap(_priority[i], _priority[j]);
                    }
                }
                else {
                    if (_enemies[first_pos]->getSpeed() < _enemies[second_pos]->getSpeed()) {
                        std::swap(_priority[i], _priority[j]);
                    }
                }
            }
        }
    }

    while (!_priority.empty()) {
        int current_entity = _priority[0];
        _priority.erase(_priority.begin());
        if (current_entity < _start_heroes) {
            if (player->getHeroes()[current_entity]->getHP() > 0) {
                for (auto skill: player->getHeroes()[current_entity]->getSkills()) {
                    addAction(player, &UseSkill(player->getHeroes()[current_entity], skill, _enemies));
                }
                for (auto item: player->getInventory().getItems()) {
                    addAction(player, &UseItem(player, item, _enemies));
                }
                return;
            }
            else {
                continue;
            }
        }
        current_entity -= _start_heroes;
        if (_enemies[current_entity]->getHP() <= 0) {
            continue;
        }
        _enemy_move(player, std::move(_enemies[current_entity]));
    }
      
    player->getMonitor()->draw();
}

std::vector<std::vector<char>> EnemyEncounter::draw() {
    std::vector<std::vector<char>> to_ret;
    for (auto &i: _enemies) {
        to_ret.insert(to_ret.end(), i->draw().begin(), i->draw().end());
    }
    return to_ret;
}