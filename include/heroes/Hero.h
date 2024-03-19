//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_HERO_H
#define UNTITLED_HERO_H
#include "entity/Entity.h"

namespace entity{
    class Hero:public entity::Entity{
        public:
        Hero(std::string name, std::map<int, int> characteristics, std::set<std::shared_ptr<skillDesigns::Skill>> skills);
    };
}
#endif //UNTITLED_HERO_H
