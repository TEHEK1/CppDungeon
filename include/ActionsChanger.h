//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_ACTIONSCHANGER_H
#define CPPDUNGEON_ACTIONSCHANGER_H
class Player;
class Action;
class ActionsChanger{
protected:
    virtual void addAction(Player*, Action*);
    virtual void removeAction(Player*, Action*);
};
#endif //CPPDUNGEON_ACTIONSCHANGER_H
