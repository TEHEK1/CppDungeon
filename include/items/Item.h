//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_ITEM_H
#define CPPDUNGEON_ITEM_H
#include "skillDesigns/RangeSkill.h"
<<<<<<< HEAD
namespace items {
    class Item : public skillDesigns::RangeSkill {
=======

namespace items {
    class Item : public skillDesigns::RangeSkill {
    public:
        Item(int size, std::string name, std::vector<int> availableRank,
                   std::vector<int> availableAllyTarget = {},
                   std::vector<int> availableEnemyTarget = {},
                   int accuracy = 0, int criticalDamageChance = 0);
        virtual std::string drawItem() = 0;
>>>>>>> 8715e9f3056b12d1f1b9081f325c75e1d05fdf1e
    };
}
#endif //CPPDUNGEON_ITEM_H
