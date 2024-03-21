#include "heroes/BountyHunter/FinishHim.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace BountyHunter {
        FinishHim::FinishHim() : skillDesigns::RangeSkill(1, "FinishHim", {1, 2, 3}, {}, {1, 2, 3}, 85, 5) {}

        void FinishHim::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            int attackModifier = 0;
            if (object->get(Characteristic::turnable) < 0) { // TODO smth with stun
                attackModifier += 25;
            }
            
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, attackModifier), battleField, crited, 100);
        }

        void FinishHim::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string FinishHim::getEffectDescription() {
            return "Damage 0% +25% DMG vs Stunned";
        }
        std::string FinishHim::getSelfDescription() {
            return "";
        }
    } // namespace BrigandFusilier
} // namespace enemies