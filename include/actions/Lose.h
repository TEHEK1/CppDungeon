//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_LOSE_H
#define MONITORTEST_LOSE_H

#include "actions/Action.h"
namespace actions {

    class Lose: public Action{
        void act(Player *) override;
        std::string getName() override;
    };

} // actions

#endif //MONITORTEST_LOSE_H
