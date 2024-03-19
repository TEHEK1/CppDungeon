//
// Created by kait on 3/19/24.
//
#include "items/FortifyingGarlic.h"

namespace items{
    namespace FortifyingGarlic{
        FortifyingGarlic::FortifyingGarlic() : Item(0, "Fortifying Garlic Effect", {1, 2, 3, 4},
                                                    {1, 2, 3, 4}, {}, 100) {};
        std::string drawItem(){
            return "Fortifying Garlic - Bleed, Blight 33%";
        }
    }//namespace FortifyingGarlic
}//namespace items