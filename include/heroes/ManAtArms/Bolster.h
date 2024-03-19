#include "skillDesigns/RangeSkill.h"

namespace Heroes {

    namespace ManAtArms {

        class Bolster: public skillDesigns::RangeSkill {
        public:
            Bolster(); // buffs all allies 
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

    } // namespace ManAtArms

} // namespace Heroes