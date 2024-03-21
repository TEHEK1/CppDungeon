#include "skillDesigns/RangeSkill.h"

namespace Heroes {

    namespace Hellion {

        class IfItBleeds: public skillDesigns::RangeSkill {
        public:
            IfItBleeds();
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            std::string getEffectDescription() override;
            std::string getSelfDescription() override;
        };

    } // namespace Hellion

} // namespace Heroes