#include "skillDesigns/Skill.h"

namespace Heroes {

    namespace Hellion {

        class IronSwan: public skillDesigns::Skill {
        public:
            IronSwan();
      
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

    } // namespace Hellion

} // namespace Heroes