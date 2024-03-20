#ifndef MUSKETEER_H
#define MUSKETEER_H

#include "entity/Hero.h"
#include "AimedShot.h"
#include "Buckshot.h"
#include "CallTheShot.h"
#include "PatchUp.h"
#include "Sidearm.h"
#include "SkeetShot.h"
#include "Smokescreen.h"

namespace Heroes {

    namespace Musketeer {

        class Musketeer:public entity::Hero{
        public:
            std::vector<std::vector<char>> drawAlive() override;
            Musketeer();
        };

    } // namespace Musketeer

} // namespace Heroes

#endif // MUSKETEER_H