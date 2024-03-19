//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_BLOODIEDNECKERCHIEF_H
#define UGABUGA_BLOODIEDNECKERCHIEF_H
#include "skillDesigns/Skill.h"
#include "items/Item.h"
#include "BloodiedNeckerchiefEffect.h"

namespace items{
    namespace BloodiedNeckerchief {
        class BloodiedNeckerchief : public Item {
        public:
            std::string drawItem() override;
            BloodiedNeckerchief();
        };
    }//namespace BloodiedNeckerchief
}//namespace items

#endif //UGABUGA_BLOODIEDNECKERCHIEF_H
