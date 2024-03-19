#include "skillDesigns/RangeSkill.h"

namespace Bosses {

    namespace GardenGuardian {

        class AnnihilatingGlare : public skillDesigns::RangeSkill {
            AnnihilatingGlare();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;

        };

    } // namespace GardenGuardian

} // namespace Boss