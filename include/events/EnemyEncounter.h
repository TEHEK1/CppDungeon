//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMYENCOUNTER_H
#define UNTITLED_ENEMYENCOUNTER_H
#include "entity/Entity.h"
#include "events/Event.h"
#include "changers/SquadChanger.h"
#include "changers/EffectChanger.h"
#include "Squad.h"
#include "BattleField.h"
#include <vector>
#include <queue>
class Enemy;
class Player;
namespace events {
    class EnemyEncounter : public Event, public SquadChanger, public changers::EffectChanger {
    public:
        EnemyEncounter();
        void turn(Player* player, std::shared_ptr<events::Event> index);
        std::shared_ptr<Squad> getEnemies();
        std::vector<std::vector<char>> draw() override;
        std::shared_ptr<BattleField> getBattleField();
    private:
        void _enemyMove(Player *, std::shared_ptr<entity::Entity>, int rank, std::shared_ptr<BattleField> battleField);
        bool _checkAlive(std::vector<std::shared_ptr<entity::Entity>>);
        std::shared_ptr<Squad> m_enemies;
        std::queue<std::shared_ptr<entity::Entity>> m_priority;
    };
} // namespace events
#endif //UNTITLED_ENEMYENCOUNTER_H
