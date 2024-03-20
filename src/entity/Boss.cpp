//
// Created by Амир Кашапов on 18.03.2024.
//
#include "entity/Boss.h"
entity::Boss::Boss(std::string name, std::map<int, int> characteristics,
                   std::set<std::shared_ptr<skillDesigns::Skill>> skills): Enemy(name, characteristics, skills) {}