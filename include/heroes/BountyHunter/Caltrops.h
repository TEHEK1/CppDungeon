#include "skillDesigns/RangeSkill.h"

namespace Heroes {

    namespace BountyHunter {

        class Caltrops: public skillDesigns::RangeSkill {
        public:
            Caltrops();
      
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

    } // namespace BountyHunter

} // namespace Heroes