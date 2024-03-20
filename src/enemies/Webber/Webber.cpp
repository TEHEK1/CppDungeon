#include "enemies/Webber/Webber.h"
#include "changers/EntityChanger.h"
enemies::Webber::Webber::Webber():
    entity::Enemy("Webber",
    {{static_cast<int>(Characteristic::accuracyModifier), 1}, 
    {static_cast<int>(Characteristic::dodge), 15},
    {static_cast<int>(Characteristic::defence), 0},
    {static_cast<int>(Characteristic::speed), 5},
    {static_cast<int>(Characteristic::HP), 8},
    {static_cast<int>(Characteristic::maxHP), 8},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::enemyType), static_cast<int>(EnemyType::Beast)},
    {static_cast<int>(Characteristic::minDamage), 1},
    {static_cast<int>(Characteristic::maxDamage), 3},
    {static_cast<int>(Characteristic::criticalDamageChance), 0},
    {static_cast<int>(Resistances::Stun), 25},
    {static_cast<int>(Resistances::Blight), 20},
    {static_cast<int>(Resistances::Bleed), 20},
    {static_cast<int>(Resistances::Debuff), 10},
    {static_cast<int>(Resistances::Move), 10}},

    {std::make_shared<Bite>(),
    std::make_shared<Web>()}){}


std::vector<std::vector<char>> enemies::Webber::Webber::drawAlive(){
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
