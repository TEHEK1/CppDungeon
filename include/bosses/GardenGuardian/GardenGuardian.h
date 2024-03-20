#ifndef GardenGuardian_H
#define GardenGuardian_H
#include "entity/Boss.h"
#include "bosses/GardenGuardian/AnnihilatingGlare.h"
#include "bosses/GardenGuardian/HatredBeyondTime.h"

namespace Bosses {

    namespace GardenGuardian {

        class GardenGuardian : public entity::Boss {
        public:
            std::vector<std::vector<char>> drawAlive() override;
            GardenGuardian();
        };

    } // namespace GardenGuardian

} // namespace Boss
#endif // GardenGuardian_H