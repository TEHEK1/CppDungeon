//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_CHOOSENEXTROOM_H
#define CPPDUNGEON_CHOOSENEXTROOM_H
#include "actions/Action.h"
#include "changers/PositionChanger.h"
#include <utility>

namespace actions {
    class ChooseNextRoom : public Action, public changers::PositionChanger {
    public:
        explicit ChooseNextRoom(char);
        void act(Player *player) override;
    private:
        char m_room;
    };
} // namespace actions
#endif //CPPDUNGEON_CHOOSENEXTROOM_H