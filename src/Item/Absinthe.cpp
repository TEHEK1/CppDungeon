//
// Created by kait on 3/19/24.
//
#include "items/Absinthe.h"

namespace items{
    namespace Absinthe{
        Absinthe::Absinthe() : Item(0, "Absinthe Effect", {1, 2, 3, 4},
                                                    {1, 2, 3, 4}, {}, 100) {};
        std::string drawItem(){
            return "Absinthe - Denis approves";
        }
    }//namespace FortifyingGarlic
}//namespace items