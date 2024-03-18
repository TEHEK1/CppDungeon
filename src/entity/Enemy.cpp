#include "entity/Enemy.h"

entity::Enemy::Enemy(std::string name, std::map<int, int> characteristics, std::set<std::shared_ptr<skillDesigns::Skill>> skills) : Entity(name, characteristics, skills) {}