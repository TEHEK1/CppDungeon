//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_BOSS_H
#define CPPDUNGEON_BOSS_H
#include "entity/Enemy.h"
namespace entity {
    class Boss : public Enemy {
        public:
        Boss(std::string name, std::map<int, int> characteristics, std::set<std::shared_ptr<skillDesigns::Skill>> skills);
    };
} // namespace entity
#endif //CPPDUNGEON_BOSS_H
