#include "skillDesigns/Skill.h"

namespace Heroes {

    namespace ManAtArms {

        class Defender: public skillDesigns::Skill {
            Defender(); 
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

    } // namespace ManAtArms

} // namespace Heroes