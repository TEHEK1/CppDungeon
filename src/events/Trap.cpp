//
// Created by Амир Кашапов on 15.03.2024.
//
#include "generators/NumberGenerator.h"
#include "events/Trap.h"
#include "player/Player.h"
#include "events/Chest.h"
#include "actions/Use.h"
#include "navigation/Cell.h"
#include "navigation/Map.h"
#include <memory>
#include "monitor/Monitor.h"
#include "actions/Use.h"
#include "actions/DontUse.h"
#include "player/Squad.h"
#include "effects/Damage.h"

void events::Trap::turn(Player * player) {
    player -> getMonitor() -> draw();
    std::shared_ptr<events::UsableEvent> ptr_Use(dynamic_cast<events::UsableEvent*>(this));
    if(m_used) {
        addAction(player, std::shared_ptr<actions::Use>(new actions::Use(ptr_Use)));
    }
    addAction(player, std::shared_ptr<actions::DontUse>(new actions::DontUse(std::shared_ptr<Trap>(this))));
}

void events::Trap::dontUse(Player *player) {
    static int random = generators::NumberGenerator::generate(0, 2);
    std::vector<std::shared_ptr<entity::Entity>> entities = player -> getSquad() -> getEntities();
    for(int i = 0; i < entities.size(); i++){
        addEffect(entities[i], std::make_shared<effects::Damage>(random));
    }
    player -> getMap() -> getCell(player->getPosition())->freeMoves(player, std::shared_ptr<events::Event>(this));
}

void events::Trap::use(Player *player) {
    static bool once = true;
    if(once) {
        once = false;
        static int random = generators::NumberGenerator::generate(0, 3);
        std::vector<std::shared_ptr<entity::Entity>> entities = player->getSquad()->getEntities();
        for (int i = 0; i < entities.size(); i++) {
            addEffect(entities[i], std::make_shared<effects::Damage>(random));
        }
        // |__/_\__|
        // |__|_|__|
        // |__\_/__|
        //
        //
        // /_\___/_\
        // |_|___|_|
        // \_/___\_/
        m_drawing[3] = {'/', '_', '\\', '_', '_', '_', '/', '_', '\\'};
        m_drawing[4] = {'|', '_', '|', '_', '_', '_', '|', '_', '|'};
        m_drawing[5] = {'\\', '_', '/', '_', '_', '_', '\\', '_', '/'};
        player->getMap()->getCell(player->getPosition())->freeMoves(player, std::shared_ptr<events::Event>(this));
        m_used = false;
    }
}

std::vector<std::vector<char>> events::Trap::draw() {
    return m_drawing;
}