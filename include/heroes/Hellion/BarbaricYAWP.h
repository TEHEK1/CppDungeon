#include "skillDesigns/RangeSkill.h"

namespace Heroes {

    namespace Hellion {

        class BarbaricYAWP: public skillDesigns::RangeSkill {
        public:
            BarbaricYAWP();
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

    } // namespace Hellion

} // namespace Heroes