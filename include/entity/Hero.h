//
// Created by Амир Кашапов on 18.03.2024.
//

#ifndef SKILLTEST_HERO_H
#define SKILLTEST_HERO_H
#include "entity/Entity.h"
#include <string>
#include <map>
namespace entity{
    class Hero: public entity::Entity{
        public:
        Hero(std::string name, std::map<int, int> characteristics, std::set<std::shared_ptr<skillDesigns::Skill>> skills);
    };
}
#endif //SKILLTEST_HERO_H
