#ifndef SKULLTOSS_H
#define SKULLTOSS_H
#include "skillDesigns/RangeSkill.h"

namespace enemies {
    namespace Ghoul {
        class SkullToss : public skillDesigns::RangeSkill {
        public:
            SkullToss();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    } // namespace Ghoul
} // namespace enemies
#endif //SKULLTOSS_H