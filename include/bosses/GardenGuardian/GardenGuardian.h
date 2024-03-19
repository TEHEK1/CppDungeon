#include "entity/Boss.h"
#include "GardenGuardian/AnnihilatingGlare.h"
#include "GardenGuardian/HatredBeyondTime.h"

namespace Bosses {

    namespace GardenGuardian {

        class GardenGuardian : public entity::Boss {
        public:
            std::vector<std::vector<char>> drawAlive() override;
            GardenGuardian();
        };

    } // namespace GardenGuardian

} // namespace Boss