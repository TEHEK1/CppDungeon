//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_TRAP_H
#define CPPDUNGEON_TRAP_H
#include "events/UsableEvent.h"
class Player;
namespace events {
    class Trap : public events::UsableEvent {
    public:
        void turn(Player *player) override;
        void use(Player *player) override;
        void dontUse(Player *player);
        std::vector<std::vector<char>> draw() override;
    };
} // namespace events
#endif //CPPDUNGEON_TRAP_H
