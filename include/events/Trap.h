//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_TRAP_H
#define CPPDUNGEON_TRAP_H
#include "events/UsableEvent.h"
#include "changers/EffectChanger.h"
class Player;
namespace events {
    class Trap : public events::UsableEvent, public changers::EffectChanger{
    public:
        void turn(Player *player) override;
        void use(Player *player) override;
        void dontUse(Player *player);
        std::vector<std::vector<char>> draw() override;
    private:
        int m_range_use_start = 0;
        int m_range_use_finish = 3;
        int m_range_dontUse_start = 0;
        int m_range_dontUse_finish = 2;
        bool m_used = true;
//    +-------+
//    |+__-__+|
//    |_+_-_+_|
//    |__/_\__|
//    |__|_|__|
//    |__\_/__|
//    |_+_-_+_|
//    |+__-__+|
//    +-------+
        std::vector<std::vector<char>> m_drawing = {{'+', '-', '-', '-',  '-', '-',  '-', '-', '+'},
                                                  {'|', '+', '_', '_',  '-', '_',  '_', '+', '|'},
                                                  {'|', '_', '+', '_',  '-', '_',  '+', '_', '|'},
                                                  {'|', '_', '_', '/',  '-', '\\', '_', '_', '|'},
                                                  {'|', '_', '_', '|',  '-', '|',  '_', '_', '|'},
                                                  {'|', '_', '_', '\\', '-', '/',  '_', '_', '|'},
                                                  {'|', '_', '+', '_',  '-', '_',  '+', '_', '|'},
                                                  {'|', '+', '_', '_',  '-', '_',  '_', '+', '|'},
                                                  {'+', '-', '-', '-',  '-', '-',  '-', '-', '+'}};
    };
} // namespace events
#endif //CPPDUNGEON_TRAP_H
