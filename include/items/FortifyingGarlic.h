//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_FORTIFYINGGARLIC_H
#define UGABUGA_FORTIFYINGGARLIC_H
#include "skillDesigns/Skill.h"
#include "items/Item.h"
#include "FortifyingGarlicEffect.h"

namespace items{
    namespace FortifyingGarlic {
        class FortifyingGarlic : public Item {
        public:
            std::string drawItem() override;
            FortifyingGarlic();
        };
    }//namespace FortifyingGarlic
}//namespace items

#endif //UGABUGA_FORTIFYINGGARLIC_H
