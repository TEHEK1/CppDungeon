#include "heroes/ManAtArms/ManAtArms.h"
#include "changers/EntityChanger.h"

Heroes::ManAtArms::ManAtArms::ManAtArms():
    entity::Hero("ManAtArms",
    {{static_cast<int>(Characteristic::accuracyModifier), 1}, 
    {static_cast<int>(Characteristic::dodge), 5},
    {static_cast<int>(Characteristic::defence), 0},
    {static_cast<int>(Characteristic::speed), 3},
    {static_cast<int>(Characteristic::HP), 31},
    {static_cast<int>(Characteristic::maxHP), 31},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::minDamage), 5},
    {static_cast<int>(Characteristic::maxDamage), 9},
    {static_cast<int>(Characteristic::criticalDamageChance), 2},
    {static_cast<int>(Resistances::Stun), 40},
    {static_cast<int>(Resistances::Blight), 30},
    {static_cast<int>(Resistances::Bleed), 40},
    {static_cast<int>(Resistances::Debuff), 30},
    {static_cast<int>(Resistances::Move), 40}},

    {std::make_shared<Bellow>(),
     std::make_shared<Bolster>(),
     std::make_shared<Command>(),
     std::make_shared<Crush>(),
     std::make_shared<Defender>(),
     std::make_shared<Rampart>(),
     std::make_shared<Retribution>()}) {};

std::vector<std::vector<char>> Heroes::ManAtArms::ManAtArms::drawAlive() {
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
        {'-', '@', '@', '%', ':', ' ', ' ', ' ', ' ', '.', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '=', '#', '.', ' ', ' ', '.', '=', '*', '*', '#', '#', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {':', '%', '@', '%', '+', '+', '%', '#', '%', '%', '%', '@', '%', '%', '@', '*', '.', ' ', ' ', ' '},
        {' ', '%', '%', '@', '@', '@', '@', '%', '%', '@', '%', '%', '#', '#', '#', '@', '*', '+', ' ', ' '},
        {' ', ':', ' ', '-', '=', '-', '+', '%', '@', '@', '@', '@', '%', '*', '+', '*', '%', '@', '.', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '+', '@', '@', '@', '%', '@', '@', '@', '%', '%', '@', '@', '%', '.'},
        {' ', ' ', ' ', ' ', ' ', ' ', '*', '@', '@', '@', '%', '@', '@', '@', '@', '@', '@', '@', ':', ' '},
        {' ', ' ', ' ', ' ', ' ', '-', '@', '%', '@', '@', '@', '@', '@', '@', '@', '@', '*', ' ', ' ', ' '}
    };
}


// -@@%:    ..         
//  =#.  .=**##.       
// :%@%++%#%%%@%%@*.   
//  %%@@@@%%@%%###@*+  
//  : -=-+%@@@@%*+*%@. 
//       +@@@%@@@%%@@%.
//       *@@@%@@@@@@@: 
//      -@%@@@@@@@@*  