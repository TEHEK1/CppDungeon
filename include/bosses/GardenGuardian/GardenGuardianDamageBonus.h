#include "skillDesigns/RangeSkill.h"
#include "skillDesigns/Skill.h"

namespace Bosses {

    namespace BloodFount {

        class GardenGuardianDamageBonus : public skillDesigns::RangeSkill {
            GardenGuardianDamageBonus();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;

        };

    } // namespace BloodFount

} // namespace Boss