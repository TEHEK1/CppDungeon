//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_CHOOSEROOMEVENT_H
#define CPPDUNGEON_CHOOSEROOMEVENT_H
#include "events/Event.h"
namespace events {
    class ChooseRoomEvent : public Event {
    public:
        virtual ~ChooseRoomEvent() = default;
        void turn(Player *) override;

        std::vector<std::vector<char>> draw() override;
    };
} // namespace events
#endif //CPPDUNGEON_CHOOSEROOMEVENT_H
