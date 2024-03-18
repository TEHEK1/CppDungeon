#include "skillDesigns/RangeSkill.h"

namespace enemies {
    namespace Webber {
        class Bite : public skillDesigns::RangeSkill {
        public:
            Bite();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    } // namespace BrigandFusilier
} // namespace enemies