#include "enemies/CultistAcolyte/StressfulIncantation.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"

namespace enemies {
    namespace CultistAcolyte {
        StressfulIncantation::StressfulIncantation() : RangeSkill(1, "StressfulIncantation", {1, 2, 3, 4}, {}, {1, 2, 3, 4}, 83, 0) {}

        void StressfulIncantation::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                                   std::shared_ptr<entity::Entity> actor,
                                                   std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
                    (crited, 1, 1), battleField, crited, 100);

        }

        void StressfulIncantation::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                                 std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies