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
class Enemy;
class Player;
namespace events {
    class EnemyEncounter : public Event, public SquadChanger, public changers::EffectChanger {
    public:
        EnemyEncounter();
        void turn(Player* player, std::shared_ptr<events::Event> index);
        Squad getEnemies();
        std::vector<std::vector<char>> draw() override;
    private:
        void _enemyMove(Player *, std::shared_ptr<entity::Entity>);
        Squad m_enemies;
    };
} // namespace events
#endif //UNTITLED_ENEMYENCOUNTER_H
