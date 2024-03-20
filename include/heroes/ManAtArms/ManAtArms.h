#ifndef MAN_AT_ARMS_H
#define MAN_AT_ARMS_H
#include "entity/Hero.h"
#include "Bellow.h"
#include "Bolster.h"
#include "Command.h"
#include "Crush.h"
#include "Defender.h"
#include "Rampart.h"
#include "Retribution.h"


namespace Heroes {

    namespace ManAtArms {

        class ManAtArms:public entity::Hero{
        public:
            std::vector<std::vector<char>> drawAlive() override;
            ManAtArms();
        };

    } // namespace ManAtArms

} // namespace Heroes
#endif // MAN_AT_ARMS_H