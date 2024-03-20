#ifndef BOUNTY_HUNTER_H
#define BOUNTY_HUNTER_H
#include "entity/Hero.h"
#include "Caltrops.h"
#include "CollectBounty.h"
#include "ComeHither.h"
#include "FinishHim.h"
#include "FlashBang.h"
#include "MarkForDeath.h"
#include "UpperCut.h"


namespace Heroes {

    namespace BountyHunter {

        class BountyHunter:public entity::Hero{
        public:
            std::vector<std::vector<char>> drawAlive() override;
            BountyHunter();
        };

    } // namespace BountyHunter

} // namespace Heroes
#endif //BOUNTY_HUNTER_H