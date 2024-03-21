#include "skillDesigns/RangeSkill.h"

namespace Heroes {

    namespace BountyHunter {

        class CollectBounty: public skillDesigns::RangeSkill {
        public:
            CollectBounty();
       
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            std::string getEffectDescription() override;
            std::string getSelfDescription() override;
        };

    } // namespace BountyHunter

} // namespace Heroes