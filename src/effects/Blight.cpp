//
// Created by artem on 13.03.2024.
//
#include "effects/Blight.h"
#include "entity/Trick.h"
namespace effects {
    Blight::Blight(std::weak_ptr<entity::Entity> entity, int numberOfTurns, int HPturner, int crited, int critModifier) :
    AutoAction(entity, crited < 0 ? numberOfTurns : numberOfTurns * critModifier / 100,
               std::map<size_t, int>{}, std::map<size_t, int>{{trick::hash("HP"), HPturner}}, crited, critModifier) {}
}