//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_ACTIONSCHANGER_H
#define CPPDUNGEON_ACTIONSCHANGER_H
#include <memory>
#include <set>
class Player;
class Action;
class ActionsChanger{
protected:
    void addAction(Player*, Action*);
    void removeAction(Player*, bool (std::set<std::unique_ptr<Action>>::iterator));
    void returnToDefault(Player*);
};
#endif //CPPDUNGEON_ACTIONSCHANGER_H
