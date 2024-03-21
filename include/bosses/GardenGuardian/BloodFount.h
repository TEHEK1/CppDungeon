#include "entity/Boss.h"
#include "bosses/GardenGuardian/GardenGuardian.h"
#include "bosses/GardenGuardian/GardenGuardianDamageBonus.h"

namespace Bosses {

    namespace BloodFount {

        class BloodFount : public entity::Boss {
        public:
            std::vector<std::vector<char>> drawAlive() override;
            BloodFount();
        };

    } // namespace BloodFount

} // namespace Boss