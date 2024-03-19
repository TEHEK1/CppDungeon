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
    auto use = std::dynamic_pointer_cast<actions::Use>((*actionIterator));
    return static_cast<bool>(use && (use->getUsableEvent()).get() == this);
}

void events::Chest::turn(Player *player) {
    player->getMap()->getCell(player->getPosition())->freeMoves(player);
    player->getMonitor()->draw(player);
    if (!m_used) {
        addUniqueAction(player, std::make_shared<actions::Use>(shared_from_this()));
    }
    player->getMap()->getCell(player->getPosition())->freeMoves(player, this);
}

void events::Chest::use(Player *player) {
    /*std::shared_ptr<items::Item> item = std::make_shared<items::Item>();//TODO: Change it to grabbing from Main fabric
    addItem(player, item);*/
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