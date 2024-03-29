#include "enemies/SwineSlasher/SwineSlasher.h"
#include "changers/EntityChanger.h"
enemies::SwineSlasher::SwineSlasher::SwineSlasher():
    entity::Enemy("SwineSlasher",
    {{static_cast<int>(Characteristic::accuracyModifier), 1}, 
    {static_cast<int>(Characteristic::dodge), 8},
    {static_cast<int>(Characteristic::defence), 25},
    {static_cast<int>(Characteristic::speed), 5},
    {static_cast<int>(Characteristic::HP), 10},
    {static_cast<int>(Characteristic::maxHP), 10},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::enemyType), static_cast<int>(EnemyType::Beast)},
    {static_cast<int>(Characteristic::minDamage), 1},
    {static_cast<int>(Characteristic::maxDamage), 3},
    {static_cast<int>(Characteristic::criticalDamageChance), 0},
    {static_cast<int>(Resistances::Stun), 10},
    {static_cast<int>(Resistances::Blight), 40},
    {static_cast<int>(Resistances::Bleed), 40},
    {static_cast<int>(Resistances::Debuff), 15},
    {static_cast<int>(Resistances::Move), 25}},

    {std::make_shared<HookWhereItHurts>()}){}


std::vector<std::vector<char>> enemies::SwineSlasher::SwineSlasher::drawAlive(){
    return {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '@', '@', '@', '@', '@', '@', '@', '@', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '#', '*', '*', '*', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '#', '*', '#', '#', '#', ' ', '#', '*', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '#', '*', '*', '*', '#', ' ', ' ', '#', '#', ' ', ' ', ' ', '*', '#', '#', '%', '%', '%', '#'},
        {'#', '*', '#', '*', '*', '#', '*', '#', '#', '#', '#', '#', '#', '#', '*', '*', '*', '*', '*', ' '},
        {'#', '#', '*', '%', '%', '#', '*', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '*', '#', ' ', ' ', '#'},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '#', '%', '#', ' ', '#', '#', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '#', '#', ' ', ' ', '#', '#', ' ', ' ', '#', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' '}
    };
}

//       #***#         
//       ****##        
//   #*### #*#         
//  #***#  ##   *##%%%#
// #*#**#*#######***** 
// ##*%%#*#     ##*#  #
//   #          ####   
//      #####          
//     #####           
//    #%# ## ***       
//    ##  ##  #*       
//   #        #  #     
//      #              
//   #          #      
