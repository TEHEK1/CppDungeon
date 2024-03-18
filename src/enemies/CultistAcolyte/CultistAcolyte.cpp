#include "enemies/CultistAcolyte/CultistAcolyte.h"
#include "changers/EntityChanger.h"

enemies::CultistAcolyte::CultistAcolyte():Enemy(
    "CultistAcolyte",
    {{static_cast<int>(Characteristic::accuracyModifier), 1}, 
    {static_cast<int>(Characteristic::dodge), 13},
    {static_cast<int>(Characteristic::defence), 0},
    {static_cast<int>(Characteristic::speed), 7},
    {static_cast<int>(Characteristic::HP), 13},
    {static_cast<int>(Characteristic::maxHP), 16},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::enemyType), static_cast<int>(EnemyType::Human)},
    {static_cast<int>(Characteristic::minDamage), 1},
    {static_cast<int>(Characteristic::maxDamage), 1},
    {static_cast<int>(Characteristic::criticalDamageChance), 0}
    {static_cast<int>(Resistances::Stun), 25},
    {static_cast<int>(Resistances::Blight), 20},
    {static_cast<int>(Resistances::Bleed), 20},
    {static_cast<int>(Resistances::Debuff), 40},
    {static_cast<int>(Resistances::Move), 10}}){}

std::vector<std::vector<char>> entity::Entity::drawAlive(){
    return {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', ':', '*', '=', '-', ':', ' ', ' ', ' ', ' ', ' ', ':', '.'},
        {' ', ' ', ' ', ' ', ' ', ' ', '-', '*', '+', '+', '#', '+', '*', '=', ' ', ' ', ' ', ' ', '#', '='},
        {' ', ' ', ' ', ' ', ' ', ' ', '+', '+', '#', '@', '#', '#', '%', '*', ':', ' ', ' ', '+', '*', ':'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', '%', '@', '%', '%', '=', ':', ':', '+', '%', '%', '+', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '.', '#', '@', '@', '@', '%', '@', '*', '*', '-', ' ', '+', ' ', ' '},
        {' ', ' ', ' ', ' ', '.', '*', '@', '#', '*', '@', '#', '#', '@', '.', ' ', ' ', ' ', '=', ' ', ' '},
        {' ', ' ', ' ', ' ', '+', '=', '-', '.', '%', '@', '#', '#', '%', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '.', '*', '@', '@', '@', '%', '@', '.', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '.', '*', '@', '@', '@', '@', '@', '@', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ':', '=', '#', '@', '@', '@', '@', '@', '@', '@', '@', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'.', '%', '@', '@', '@', '%', '%', '%', '@', '@', '@', '@', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '.', '*', '@', '@', '@', '@', '@', '@', '@', '@', '%', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '.', '+', '%', '@', '@', '@', '@', '@', '%', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
}

//        .:*=-:     :.
//       -*++#+*=    #=
//       ++#@##%*:  +*:
//        -%@%%=::+%%+ 
//       .#@@@%@**- +  
//     .*@#*@##@.   =  
//     +=-.%@##%       
//       .*@@@%@.      
//     .*@@@@@@@       
//  :=#@@@@@@@@@       
// .%@@@%%%@@@@*       
//  .*@@@@@@@@%        
//   .+%@@@@@%.  
