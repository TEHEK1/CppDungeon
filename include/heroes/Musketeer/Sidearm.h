#include "skillDesigns/Skill.h"

namespace Heroes {

    namespace Musketeer {

        class Sidearm: public skillDesigns::Skill {
        public:
            Sidearm();
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

    } // namespace Musketeer

} // namespace Heroes