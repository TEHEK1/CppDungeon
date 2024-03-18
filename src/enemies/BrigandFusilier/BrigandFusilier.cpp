#include "enemies/BrigandFusier/BrigandFusilier.h"
#include "changers/EntityChanger.h"

enemies::BrigandFusilier::BrigandFusilier():Enemy("BrigandFusilier",
    {{static_cast<int>(Characteristic::accuracyModifier), 1}, 
    {static_cast<int>(Characteristic::dodge), 8},
    {static_cast<int>(Characteristic::defence), 0},
    {static_cast<int>(Characteristic::speed), 6},
    {static_cast<int>(Characteristic::HP), 12},
    {static_cast<int>(Characteristic::maxHP), 15},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::enemyType), static_cast<int>(EnemyType::Human)},
    {static_cast<int>(Characteristic::minDamage), 1},
    {static_cast<int>(Characteristic::maxDamage), 3},
    {static_cast<int>(Characteristic::criticalDamageChance), 0},
    {static_cast<int>(Resistances::Stun), 25},
    {static_cast<int>(Resistances::Blight), 20},
    {static_cast<int>(Resistances::Bleed), 20},
    {static_cast<int>(Resistances::Debuff), 15},
    {static_cast<int>(Resistances::Move), 25}}){}


std::vector<std::vector<char>> entity::Entity::drawAlive(){
    return {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
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
