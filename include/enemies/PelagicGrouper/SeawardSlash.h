#include "skillDesigns/RangeSkill.h"

namespace enemies {
    namespace PelagicGrouper {
        class SeawardSlash : public skillDesigns::RangeSkill {
        public:
            SeawardSlash();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    } // namespace PelagicGrouper
} // namespace enemies