//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_ACTIONSCHANGER_H
#define CPPDUNGEON_ACTIONSCHANGER_H
class Player;
class Action;
class ActionsChanger{
protected:
    void addAction(Player*, Action*);
    void removeAction(Player*, Action*);
    void returnToDefault(Player*);
};
#endif //CPPDUNGEON_ACTIONSCHANGER_H
