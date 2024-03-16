//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_ACTIONSCHANGER_H
#define CPPDUNGEON_ACTIONSCHANGER_H
#include <functional>
#include <memory>
#include <set>
class Player;
#include "namespaces/actions.h"
namespace changers {
    class ActionsChanger {
    protected:
        void addAction(Player *player, const std::shared_ptr<actions::Action>& action);
        void removeAction(Player *player, std::shared_ptr<actions::Action>& action);
        void removeAction(Player *player, std::function<bool(std::set<std::shared_ptr<actions::Action>>::iterator)> actionIterator);

        void returnToDefault(Player *player);

        std::set<std::shared_ptr<actions::Action> > &getActions(Player *player);
    };
} // namespace changers
#endif //CPPDUNGEON_ACTIONSCHANGER_H
