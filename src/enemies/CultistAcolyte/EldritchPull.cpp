#include "enemies/CultistAcolyte/EldritchPull.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/ForceMove.h"
namespace enemies {
    namespace CultistAcolyte {
        EldritchPull::EldritchPull() : RangeSkill(1, "Eldritch Pull", {1, 2, 3, 4}, {}, {3, 4}, 83, 6) {}

        void EldritchPull::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                           std::shared_ptr<entity::Entity> actor,
                                           std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
                    (crited, 1, 1), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::ForceMove>
                    (crited, -2), battleField, crited, 100);
        }

        void EldritchPull::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                         std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies