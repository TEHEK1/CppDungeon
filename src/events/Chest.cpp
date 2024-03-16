//
// Created by artem on 28.02.2024.
//
#include "events/Event.h"
#include "player/Player.h"
#include "events/Chest.h"
#include "actions/Use.h"
#include "navigation/Cell.h"
#include "navigation/Map.h"
#include "items/Item.h"
#include <memory>
#include "monitor/Monitor.h"

bool events::Chest::comp(std::set<std::shared_ptr<actions::Action>>::iterator actionIterator) {
//    if (typeid(*((*actionIterator).get())) == typeid(Use)) {
//        Use* use = static_cast<Use*>((*actionIterator).get());
//        if (use->getChest() == this) {
//            return true;
//        }
//    }
//std::dynamic_pointer_cast<Use>()
    std::shared_ptr<actions::Use> use = std::dynamic_pointer_cast<actions::Use>((*actionIterator));
    return static_cast<bool>(use && (use->getChest()).get() == this);
}

void events::Chest::turn(Player *player) {
    player->getMonitor()->draw();
    if (!m_used) {
        std::shared_ptr<actions::Action> useAction(new actions::Use(std::shared_ptr<Chest>(this)));
        addAction(player, std::move(useAction));
    }
    player->getMap()->getCell(player->getPosition())->freeMoves(player, std::shared_ptr<Event>(this));
}

void events::Chest::use(Player *player) {
    std::shared_ptr<items::Item> item = std::make_shared<items::Item>();//TODO: Change it to grabbing from Main fabric
    addItem(player, item);
    removeAction(player, [this](std::set<std::shared_ptr<actions::Action>>::iterator actionIterator){return comp(actionIterator);});
    m_used = true;
}

std::vector<std::vector<char>> events::Chest::draw() {
//     -------
//    |___-___|
//    |__|_|__|
//    |___-___|
//     -------
    return {{' ', '-', '-', '-', '-', '-', '-', '-', ' ' },
            {'|', '_', '_', '_', '-', '_', '_', '_', '|' },
            {'|', '_', '_', '|', '-', '|', '_', '_', '|' },
            {'|', '_', '_', '_', '-', '_', '_', '_', '|' },
            {' ', '-', '-', '-', '-', '-', '-', '-', ' ' }};
}