#include "skillDesigns/Skill.h"

namespace NPC {
    namespace PlagueDoctor{
        class BattlefieldMedicine : public skillDesigns::Skill{
            BattlefieldMedicine();
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                        std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    }
}