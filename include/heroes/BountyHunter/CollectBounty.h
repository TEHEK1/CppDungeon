#include "skillDesigns/Skill.h"

namespace Heroes {

    namespace BountyHunter {

        class CollectBounty: public skillDesigns::Skill {
        public:
            CollectBounty();
       
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

    } // namespace BountyHunter

} // namespace Heroes