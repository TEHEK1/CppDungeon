#include "skillDesigns/RangeSkill.h"

namespace enemies {
    namespace RabidGnasher {
        class RabidRush : public skillDesigns::RangeSkill {
        public:
            RabidRush();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    } // namespace RabidGnasher
} // namespace enemies