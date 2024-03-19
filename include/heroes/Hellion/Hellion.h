#ifndef HELLION_H
#define HELLION_H

#include "entity/Hero.h"
#include "AdrenalineRush.h"
#include "BarbaricYAWP.h"
#include "BleedOut.h"
#include "Breakthrough.h"
#include "IfItBleeds.h"
#include "IronSwan.h"
#include "WickedHack.h"

namespace Heroes {

    namespace Hellion {

        class Hellion:public entity::Hero{
        public:
            std::vector<std::vector<char>> drawAlive() override;
            Hellion();
        };

    } // namespace Hellion

} // namespace Heroes


#endif // HELLION_H