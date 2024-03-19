#include "heroes/BountyHunter/BountyHunter.h"
#include "changers/EntityChanger.h"

Heroes::BountyHunter::BountyHunter::BountyHunter():
    entity::Hero("BountyHunter",
    {{static_cast<int>(Characteristic::accuracyModifier), 1},
    {static_cast<int>(Characteristic::dodge), 5},
    {static_cast<int>(Characteristic::defence), 0},
    {static_cast<int>(Characteristic::speed), 5},
    {static_cast<int>(Characteristic::HP), 25},
    {static_cast<int>(Characteristic::maxHP), 16},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::minDamage), 5},
    {static_cast<int>(Characteristic::maxDamage), 10},
    {static_cast<int>(Characteristic::criticalDamageChance), 4},
    {static_cast<int>(Resistances::Stun), 40},
    {static_cast<int>(Resistances::Blight), 30},
    {static_cast<int>(Resistances::Bleed), 30},
    {static_cast<int>(Resistances::Debuff), 30},
    {static_cast<int>(Resistances::Move), 40}},

    {std::make_shared<CollectBounty>(),
     std::make_shared<MarkForDeath>(),
     std::make_shared<ComeHither>(),
     std::make_shared<UpperCut>(),
     std::make_shared<FlashBang>(),
     std::make_shared<FinishHim>(),
     std::make_shared<Caltrops>()}) {};

std::vector<std::vector<char>> Heroes::BountyHunter::BountyHunter::drawAlive() {
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
        {':', '-', ' ', ' ', ' ', ' ', ' ', '-', '+', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'*', '%', '#', ':', ' ', ' ', '.', '@', '%', '#', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'-', '%', '%', '+', ' ', ' ', '+', '@', '@', '@', '%', '#', '=', '.', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '+', '.', ' ', ':', '@', '@', '@', '@', '%', '@', '%', '%', '*', '=', ' ', ' ', ' ', ' '},
        {' ', ' ', '*', '@', '=', '#', '@', '@', '@', '%', '@', '@', '@', '@', '@', '*', ':', ' ', ' ', ' '},
        {' ', ' ', '.', '#', '*', '#', '@', '@', '@', '%', '@', '@', '@', ':', ' ', ' ', ' ', '-', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ':', '@', '@', '@', '@', '@', '@', '%', ' ', ' ', ' ', '#', '.', '.'},
        {' ', ' ', ' ', ' ', ' ', '.', '%', '@', '@', '@', '@', '@', '@', '%', ' ', ' ', ' ', ' ', ':', ' '}
    };
}


// :-     -+.          
// *%#:  .@%#.         
// -%%+  +@@@%#=.      
//   +. :@@@@%@%%*=    
//   *@=#@@@%@@@@@*:   
//   .#*#@@@%@@@:   -  
//       :@@@@@@%   #..
//      .%@@@@@@%    : 