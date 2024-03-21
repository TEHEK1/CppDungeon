#include "heroes/Musketeer/AimedShot.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Musketeer {
        AimedShot::AimedShot(): skillDesigns::RangeSkill(1, "AimedShot", {3, 4}, {}, {2, 3, 4}, 95, 5) {}

        void AimedShot::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            int attackModifier = 0;
            if (object->get(Characteristic::marked) > 0) {
                attackModifier += 50;
            }

            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, attackModifier), battleField, crited, 100);
        }

        void AimedShot::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string AimedShot::getEffectDescription() {
            return "Damage +0% +50% DMG vs Marked +9% CRIT vs Marked";
        }
        std::string AimedShot::getSelfDescription() {
            return "";
        }
    } // namespace Musketeer
} // namespace Heroes