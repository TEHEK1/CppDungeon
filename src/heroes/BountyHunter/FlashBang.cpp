#include "heroes/BountyHunter/FlashBang.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/ForceMove.h"
#include "generators/NumberGenerator.h"
namespace Heroes {
    namespace BountyHunter {
        FlashBang::FlashBang() : RangeSkill(1, "FlashBang", {2, 3, 4}, {}, {2, 3, 4}, 95, 0) {}

        void FlashBang::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::ForceMove>
            (crited, generators::NumberGenerator::generate(1, 3)), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff> // TODO smth with stun
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::turnable), -1}}), battleField, crited, 110);
        }

        void FlashBang::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies