#include "enemies/CultistBrawler/CultistBrawler.h"
#include "changers/EntityChanger.h"

enemies::CultistBrawler::CultistBrawler::CultistBrawler():
        Enemy("CultistBrawler",
              {{static_cast<int>(Characteristic::accuracyModifier), 1},
               {static_cast<int>(Characteristic::dodge), 0},
               {static_cast<int>(Characteristic::defence), 0},
               {static_cast<int>(Characteristic::speed), 5},
               {static_cast<int>(Characteristic::HP), 15},
               {static_cast<int>(Characteristic::maxHP), 15},
               {static_cast<int>(Characteristic::marked), 0},
               {static_cast<int>(Characteristic::turnable), 0},
               {static_cast<int>(Characteristic::movable), 0},
               {static_cast<int>(Characteristic::enemyType), static_cast<int>(EnemyType::Human)},
               {static_cast<int>(Characteristic::minDamage), 0},
               {static_cast<int>(Characteristic::maxDamage), 0},
               {static_cast<int>(Characteristic::criticalDamageChance), 0},
               {static_cast<int>(Resistances::Stun), 25},
               {static_cast<int>(Resistances::Blight), 20},
               {static_cast<int>(Resistances::Bleed), 20},
               {static_cast<int>(Resistances::Debuff), 15},
               {static_cast<int>(Resistances::Move), 25}},

              {std::make_shared<RendForTheOldGods>(),
               std::make_shared<StumblingScratch>()}){}

std::vector<std::vector<char>> enemies::CultistBrawler::CultistBrawler::drawAlive(){
    return {
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', '#', '#', '%', ' ', ' ', ' ', '%', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', '%', '#', ' ', '%', '#', '*', '#', ' ', ' ', ' ', ' ', '%', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', '%', '%', '%', '%', '%', '%', '#', ' ', ' ', '#', ' ', ' ', '%', '%', ' '},
            {' ', ' ', ' ', ' ', '%', '#', '*', '%', '%', '*', '*', '#', '%', '*', '*', ' ', ' ', '%', '%', ' '},
            {' ', '%', '%', '%', '#', '%', '%', '%', '%', '%', '#', '*', '#', '#', '%', ' ', '%', '#', '%', '%'},
            {' ', '%', '#', '%', '%', '#', '#', '*', '#', '#', '#', '#', '%', '%', '%', ' ', '%', '%', '%', ' '},
            {' ', ' ', '%', '%', '%', ' ', ' ', ' ', ' ', '%', ' ', ' ', '%', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', '%', '%', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', '%', '#', '#', ' ', ' ', '%', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '%', '#', '%', '%', '%', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', '%', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', ' '}
    };
}


//         %##%   %
//      %# %#*#    %
//      %%%%%%#  #  %%
//     %#*%%**#%**  %%
//  %%%#%%%%%#*##% %#%%
//  %#%%##*####%%% %%%
//   %%%    %  %
//           %%%
//          %%##  %
//          #%#%%%
//          %       %
//        %        %
//       %           %