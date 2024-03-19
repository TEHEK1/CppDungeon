//
// Created by kait on 3/19/24.
//
#include "items/BloodiedNeckerchief.h"

namespace items{
    namespace BloodiedNeckerchief{
        BloodiedNeckerchief::BloodiedNeckerchief() : Item(0, "Bloodied Neckerchief Effect", {1, 2, 3, 4},
                                                    {1, 2, 3, 4}, {}, 100) {};
        std::string drawItem(){
            return "Bloodied Neckerchief - +2 speed, +10 dodge";
        }
    }//namespace BloodiedNeckerchief
}//namespace items