#include "ActionsChanger.h"
#include "Enemy.h"
#include "EnemyEncounter.h"
#include "Hero.h"
#include "Map.h"
#include "Monitor.h"
#include "Player.h"
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

void EnemyEncounter::turn(Player *player, int index) {
    bool heroes_alive = false;
    bool enemies_alive = false;

    for (auto i: player->getHeroes()) {
        if (i->getHP() > 0) {
            heroes_alive = true;
            break;
        }
    }
    for (auto &i: getEnemies()) {
        if (i->getHP() > 0) {
            enemies_alive = true;
            break;
        }
    }
    if (!(heroes_alive && enemies_alive)) {
        player->getMap()->getCell(player->getPosition())->freeMoves(player, index);
        player->getMonitor()->draw();
        return;
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