//
// Created by artem on 12.03.2024.
//
#include "effects/Disease.h"
#include "entity/Entity.h"
namespace effects {
    Disease::Disease(std::map<size_t, int> modifier) : Effect(modifier) {}

    std::function<int(entity::Entity)> Disease::getTurnFunction() {
        return [](entity::Entity object){return 1;};
    }
    std::function<int(entity::Entity)> Disease::getEndBattleTurnFunction(){
        return [](entity::Entity object){return 1;};
    }
}