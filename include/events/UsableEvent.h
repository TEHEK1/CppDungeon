//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef CPPDUNGEON_USABLEEVENT_H
#define CPPDUNGEON_USABLEEVENT_H
#include "events/Event.h"
namespace events {
    class UsableEvent: public Event{
        virtual void use(Player*) = 0;
    };

} // namespace events

#endif //CPPDUNGEON_USABLEEVENT_H
