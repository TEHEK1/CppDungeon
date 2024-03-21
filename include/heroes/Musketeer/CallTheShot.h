#include "skillDesigns/RangeSkill.h"

namespace Heroes {

    namespace Musketeer {

        class CallTheShot: public skillDesigns::RangeSkill {
        public:
            CallTheShot();
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            std::string getEffectDescription() override;
            std::string getSelfDescription() override;
        };

    } // namespace Musketeer

} // namespace Heroes