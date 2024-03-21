//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_WIN_H
#define MONITORTEST_WIN_H
#include "actions/Action.h"
namespace actions {

    class Win: public Action{
        void act(Player *) override;
        std::string getName() override;
    };

} // actions

#endif //MONITORTEST_WIN_H
