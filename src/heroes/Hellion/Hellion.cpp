#include "heroes/Hellion/Hellion.h"
#include "changers/EntityChanger.h"

Heroes::Hellion::Hellion::Hellion():
    entity::Hero("Hellion",
    {{static_cast<int>(Characteristic::accuracyModifier), 0}, 
    {static_cast<int>(Characteristic::dodge), 10},
    {static_cast<int>(Characteristic::defence), 0},
    {static_cast<int>(Characteristic::speed), 5},
    {static_cast<int>(Characteristic::HP), 26},
    {static_cast<int>(Characteristic::maxHP), 26},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::minDamage), 6},
    {static_cast<int>(Characteristic::maxDamage), 12},
    {static_cast<int>(Characteristic::criticalDamageChance), 5},
    {static_cast<int>(Resistances::Stun), 40},
    {static_cast<int>(Resistances::Blight), 40},
    {static_cast<int>(Resistances::Bleed), 40},
    {static_cast<int>(Resistances::Debuff), 30},
    {static_cast<int>(Resistances::Move), 40}},

    {std::make_shared<AdrenalineRush>(),
     std::make_shared<BarbaricYAWP>(),
     std::make_shared<BleedOut>(),
     std::make_shared<Breakthrough>(),
     std::make_shared<IfItBleeds>(),
     std::make_shared<IronSwan>(),
     std::make_shared<WickedHack>()}) {};

std::vector<std::vector<char>> Heroes::Hellion::Hellion::drawAlive() {
    return {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '.', ' ', ':', '.', ' ', ' ', ' ', ' ', ' ', ' ', '-', '-', ':', '-', '='},
        {' ', ' ', ':', '%', '@', '@', '@', '%', '#', '.', ' ', ' ', ' ', '.', '+', '%', '%', '#', '-', ' '},
        {' ', ' ', ' ', ':', '@', '+', '#', '#', '+', '+', '.', '=', '#', '+', ' ', ':', ' ', ' ', ' ', ' '},
        {' ', ' ', '-', '#', '@', '%', '%', '%', '#', '*', '%', '%', '=', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '*', '@', '%', '@', '@', '%', ':', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ':', '=', '=', '#', '@', '@', '%', '%', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'-', ':', ' ', '-', '%', '@', '@', '@', '@', '@', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
}

//      . :.      --:-=
//   :%@@@%#.   .+%%#- 
//    :@+##++.=#+ :    
//   -#@%%%#*%%=       
//   *@%@@%:           
//  :==#@@%%-          
// -: -%@@@@@#         