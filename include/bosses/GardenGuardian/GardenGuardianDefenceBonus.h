#include "skillDesigns/RangeSkill.h"

namespace Bosses {

    namespace StoneShield {

        class GardenGuardianDefenceBonus : public skillDesigns::RangeSkill {
        public:
            GardenGuardianDefenceBonus();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;

        };

    } // namespace StoneShield

} // namespace Boss