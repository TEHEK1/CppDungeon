//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_ACTIONSCHANGER_H
#define CPPDUNGEON_ACTIONSCHANGER_H
#include <functional>
#include <memory>
#include <set>
class Player;
namespace actions {
    class Action;
} // namespace actions
namespace changers {
    class ActionsChanger {
    protected:
        void addAction(Player *, std::shared_ptr<actions::Action>);

        void removeAction(Player *, std::function<bool(std::set<std::shared_ptr<actions::Action>>::iterator)>);

        void returnToDefault(Player *);

        std::set<std::shared_ptr<actions::Action> > &getActions(Player *);
    };
} // namespace changers
#endif //CPPDUNGEON_ACTIONSCHANGER_H
