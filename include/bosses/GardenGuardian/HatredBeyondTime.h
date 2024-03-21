#ifndef HatredBeyondTime_H
#define HatredBeyondTime_H
#include "skillDesigns/RangeSkill.h"

namespace Bosses {

    namespace GardenGuardian {

        class HatredBeyondTime : public skillDesigns::RangeSkill {
        public:
            HatredBeyondTime();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;

        };

    } // namespace GardenGuardian

} // namespace Boss
#endif // HatredBeyondTime_H