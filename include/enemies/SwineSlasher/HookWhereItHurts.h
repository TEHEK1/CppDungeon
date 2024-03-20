#include "skillDesigns/RangeSkill.h"

namespace enemies {
    namespace SwineSlasher {
        class HookWhereItHurts : public skillDesigns::RangeSkill {
        public:
            HookWhereItHurts();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    } // namespace SwineSlasher
} // namespace enemies