#include "EnemyEncounter.h"
#include "Enemy.h"
#include "Player.h"
#include "Monitor.h"
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

        i = new Enemy(accuracyModifier,
                        criticalDamagehance,
                        damage,
                        dodge,
                        defence,
                        speed,
                        HP);    
    }
}

EnemyEncounter::~EnemyEncounter() {
    for (auto &i: _enemies) {
        delete i;
    }
}

std::vector<Enemy*> EnemyEncounter::getEnemies() {
    return _enemies;
}

void EnemyEncounter::turn(Player *player, int index) {
    for (auto i: player->getHeroes()) {

    }
    Monitor::draw();
}

std::vector<std::vector<char>> EnemyEncounter::draw() {
    std::vector<std::vector<char>> to_ret;
    for (auto i: _enemies) {
        to_ret.insert(to_ret.end(), i->draw().begin(), i->draw().end());
    }
    return to_ret;
}