//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_NPC_H
#define CPPDUNGEON_NPC_H
#include "heroes/Hero.h"
#include "MarkedAsAutoTurn.h"
class NPC : public entity::Hero, public MarkedAsAutoTurn {
private:
    std::shared_ptr<entity::Entity> actor;
    std::vector<std::shared_ptr<entity::Entity>> objects;
public:
    NPC(std::string name, std::map<int, int> characteristics, std::set<std::shared_ptr<skillDesigns::Skill>> skills) 
        : entity::Hero(name, characteristics, skills), actor(nullptr), objects({}) {}

    void autoTurn(std::shared_ptr<BattleField> battlefield) override {
        if (auto skill = std::dynamic_pointer_cast<skillDesigns::Skill>(battlefield)) {
            if (skill->isUsable(battlefield, actor, objects).empty()) {
                skill->apply();
            }
        }
    }
};

#endif //CPPDUNGEON_NPC_H
