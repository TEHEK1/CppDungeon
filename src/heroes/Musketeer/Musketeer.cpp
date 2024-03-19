#include "heroes/Musketeer/Musketeer.h"
#include "changers/EntityChanger.h"

Heroes::Musketeer::Musketeer::Musketeer():
    entity::Hero("Musketeer",
    {{static_cast<int>(Characteristic::accuracyModifier), 1}, 
    {static_cast<int>(Characteristic::dodge), 0},
    {static_cast<int>(Characteristic::defence), 0},
    {static_cast<int>(Characteristic::speed), 3},
    {static_cast<int>(Characteristic::HP), 27},
    {static_cast<int>(Characteristic::maxHP), 27},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::minDamage), 4},
    {static_cast<int>(Characteristic::maxDamage), 8},
    {static_cast<int>(Characteristic::criticalDamageChance), 4},
    {static_cast<int>(Resistances::Stun), 40},
    {static_cast<int>(Resistances::Blight), 30},
    {static_cast<int>(Resistances::Bleed), 30},
    {static_cast<int>(Resistances::Debuff), 30},
    {static_cast<int>(Resistances::Move), 40}},

    {std::make_shared<AimedShot>(),
     std::make_shared<Buckshot>(),
     std::make_shared<CallTheShot>(),
     std::make_shared<PatchUp>(),
     std::make_shared<Sidearm>(),
     std::make_shared<SkeetShot>(),
     std::make_shared<Smokescreen>()}) {};

std::vector<std::vector<char>> Heroes::Musketeer::Musketeer::drawAlive() {
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
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', '*', '#', '*', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '@', '%', '@', '%', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '%', '%', '#', '%', '#', '=', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ':', ':', '-', '*', '#', '%', '@', '%', '#', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '#', '%', '%', '#', '%', '#', '#', '%', '%', '%', '*', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '-', '=', '#', '*', '#', '%', '%', '#', '%', '%', '@', '%', ' ', ' ', ' ', ' ', ' ', ' '},
        {'-', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '#', '=', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ':', '-', '=', '%', '@', '%', '@', '@', '@', '@', '@', '-', '.', '-', '=', '-', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', '@', '@', '@', '@', '@', '@', '@', '-', ' ', ' ', ' ', ' ', ':', '-'},
        {' ', ' ', ' ', ' ', '.', '@', '@', '=', '-', '+', '*', '*', '#', '=', ' ', ' ', ' ', ' ', ' ', ' '}
    };
}


//         -*#*.       
//        +@%@%-       
//        .%%#%#=      
//    ::-*#%@%#.       
//    #%%#%##%%%*      
//   -=#*#%%#%%@%      
// -@@@@@@@@@@@@#=     
//   :-=%@%@@@@@-.-=-  
//      #@@@@@@@-    :-
//     .@@=-+**#=      