#include "skillDesigns/RangeSkill.h"

namespace Heroes {

    namespace BountyHunter {

        class MarkForDeath: public skillDesigns::RangeSkill {
        public:
            MarkForDeath();
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

    } // namespace BountyHunter

} // namespace Heroes