//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_CHOOSEROOMEVENT_H
#define CPPDUNGEON_CHOOSEROOMEVENT_H
#include "events/Event.h"
class ChooseRoomEvent:public Event{
public:
    void turn(Player*) override;
    std::vector<std::vector<char>> draw() override;
};
#endif //CPPDUNGEON_CHOOSEROOMEVENT_H
