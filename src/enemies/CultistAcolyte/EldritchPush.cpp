#include "enemies/CultistAcolyte/EldritchPush.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/ForceMove.h"
namespace enemies {
    namespace CultistAcolyte {
        EldritchPush::EldritchPush() : RangeSkill(1, "Eldritch Push", {2, 3, 4}, {}, {1, 2}, 83, 6) {}

        void EldritchPush::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                           std::shared_ptr<entity::Entity> actor,
                                           std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
                    (crited, 1, 1), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::ForceMove>
                    (crited, 2), battleField, crited, 100);
        }

        void EldritchPush::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                         std::shared_ptr<entity::Entity> object) {
        }
    } // namespace BrigandFusilier
} // namespace enemies