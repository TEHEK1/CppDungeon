#include "entity/Boss.h"
#include "bosses/GardenGuardian/GardenGuardian.h"
#include "bosses/GardenGuardian/GardenGuardianDefenceBonus.h"

namespace Bosses {

    namespace StoneShield {

        class StoneShield : public entity::Boss {
        public:
            std::vector<std::vector<char>> drawAlive() override;
            StoneShield();
        };

    } // namespace StoneShield

} // namespace Boss