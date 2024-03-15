//
// Created by artem on 12.03.2024.
//
#include "effects/PassiveBuff.h"
#include "entity/Entity.h"
namespace effects {
    PassiveBuff::PassiveBuff(int numberOfBattles, std::map<int, int> modifier):
            PermanentEffect(modifier), MarkedAsEndBattle(numberOfBattles) {}

}