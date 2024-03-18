//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMYENCOUNTER_H
#define UNTITLED_ENEMYENCOUNTER_H
#include "entity/Entity.h"
#include "events/Event.h"
#include "Squad.h"
#include <vector>
class Enemy;
class Player;
namespace events {
    class EnemyEncounter : public Event {
    public:
        EnemyEncounter();

        void turn(std::shared_ptr<Player> player, int index);

        Squad getEnemies();

        std::vector<std::vector<char>> draw() override;

    private:
        void _enemyMove(Player *, std::shared_ptr<entity::Entity>);

        int m_start_enemies;
        int m_start_heroes;
        Squad m_enemies;
    };
} // namespace events
#endif //UNTITLED_ENEMYENCOUNTER_H
