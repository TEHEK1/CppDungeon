//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_CHOOSENEXTROOM_H
#define CPPDUNGEON_CHOOSENEXTROOM_H
#include "Action.h"
#include "Player.h"
#include "Cell.h"
#include "PositionChanger.h"
#include <utility>

namespace actions {
    class ChooseNextRoom : public Action, public PositionChanger {
    public:
        ChooseNextRoom(char);
        void act(Player *) override;
    private:
        char m_room;
    };
}
#endif //CPPDUNGEON_CHOOSENEXTROOM_H