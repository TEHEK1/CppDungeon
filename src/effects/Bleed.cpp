//
// Created by artem on 13.03.2024.
//
#include "effects/Bleed.h"
#include "entity/Trick.h"
namespace effects {
    Bleed::Bleed(std::weak_ptr<entity::Entity> entity, int numberOfTurns, int HPturner, int crited, int critModifier):
    AutoAction(entity, crited < 0 ? numberOfTurns : numberOfTurns * 150 / 100,
               std::map<size_t, int>{}, std::map<size_t, int>{{trick::hash("HP"), HPturner}}, crited, critModifier){};
}