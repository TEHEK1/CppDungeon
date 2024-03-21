#include "heroes/BountyHunter/UpperCut.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/ForceMove.h"
namespace Heroes {
    namespace BountyHunter {
        UpperCut::UpperCut() : skillDesigns::RangeSkill(1, "UpperCut", {1, 2}, {}, {1, 2}, 90, 0) {}

        void UpperCut::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -67), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::ForceMove>
            (crited, 2), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff> // TODO smth with stun
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::turnable), -1}}), battleField, crited, 100);
        }

        void UpperCut::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string UpperCut::getEffectDescription() {
            return "Damage -67%\nKnockback 2 (100% base)\nStun (100% base)";
        }
        std::string UpperCut::getSelfDescription() {
            return "";
        }
    } // namespace BountyHunter
} // namespace enemies