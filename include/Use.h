//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_USE_H
#define CPPDUNGEON_USE_H
#include "Action.h"
class Chest;
namespace actions {
    class Use : public Action {
    public:
        Use(Chest *, int);

        void act(Player *) override;

        Chest *getChest();

    private:
        int m_index;
        Chest *m_chest;
    };

#endif //CPPDUNGEON_USE_H
}