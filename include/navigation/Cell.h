//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H
#include "events/Event.h"
#include <vector>
class Player;
class Cell: public changers::ActionsChanger{
public:
    void freeMoves(Player*, events::Event*);
    void freeMoves(Player*);
    virtual void generateEvents(Player* player) = 0;
    std::vector<std::shared_ptr<events::Event>> getEvents();
    char getLevel();
    virtual ~Cell() = default;
protected:
    std::vector<std::shared_ptr<events::Event>> m_events;
private:
    std::set<events::Event*> m_endedEvents;
};
#endif //UNTITLED_CELL_H