//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_BOSSENCOUNTER_H
#define MONITORTEST_BOSSENCOUNTER_H
#include "EnemyEncounter.h"
namespace events {

    class BossEncounter: public EnemyEncounter{
    public:
        void turn(Player *player) override;
        BossEncounter();
    };

} // events

#endif //MONITORTEST_BOSSENCOUNTER_H
