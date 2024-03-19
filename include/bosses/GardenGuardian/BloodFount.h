#include "entity/Boss.h"
#include "GardenGuardian/GardenGuardian.h"
#include "GardenGuardian/GardenGuardianDamageBonus.h"

namespace Bosses {

    namespace BloodFount {

        class BloodFount : public entity::Boss {
        public:
            std::vector<std::vector<char>> drawAlive() override;
            BloodFount();
        };

    } // namespace BloodFount

} // namespace Boss