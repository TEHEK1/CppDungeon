//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_ABSINTHE_H
#define UGABUGA_ABSINTHE_H
#include "skillDesigns/Skill.h"
#include "items/Item.h"
#include "AbsintheEffect.h"

namespace items{
    namespace Absinthe {
        class Absinthe : public Item {
        public:
            std::string drawItem() override;
            Absinthe();
        };
    }//namespace Absinthe
}//namespace items

#endif //UGABUGA_ABSINTHE_H
