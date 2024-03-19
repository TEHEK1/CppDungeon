#include "skillDesigns/Skill.h"

namespace Heroes {

    namespace BountyHunter {

        class UpperCut: public skillDesigns::Skill {
            UpperCut();
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

    } // namespace BountyHunter

} // namespace Heroes