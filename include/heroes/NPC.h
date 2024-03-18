//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_NPC_H
#define CPPDUNGEON_NPC_H
#include "heroes/Hero.h"
#include "MarkedAsAutoTurn.h"
class NPC:public Hero, public MarkedAsAutoTurn{
private:
    std::shared_ptr<entity::Entity> actor;
    std::vector<std::shared_ptr<entity::Entity>> objects;
public:
    void autoTurn(std::shared_ptr<BattleField> battlefield) override {
        if (auto skill = std::dynamic_pointer_cast<skillDesigns::Skill>(battlefield)) {
            if (skill->isUsable(battlefield, actor, objects).empty()) {

            }
        }
    }
};
#endif //CPPDUNGEON_NPC_H
