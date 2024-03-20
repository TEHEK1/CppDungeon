#include "entity/Boss.h"
#include "GardenGuardian/GardenGuardian.h"
#include "GardenGuardian/GardenGuardianDefenceBonus.h"

namespace Bosses {

    namespace StoneShield {

        class StoneShield : public entity::Boss {
        public:
            std::vector<std::vector<char>> drawAlive() override;
            StoneShield();
        };

    } // namespace StoneShield

} // namespace Boss