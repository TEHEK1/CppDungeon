#include "heroes/Hellion/Breakthrough.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Hellion {
        Breakthrough::Breakthrough() : skillDesigns::RangeSkill(3, "Breakthrough", {2, 3, 4}, {}, {1, 2, 3, 4}, 85, -1) {}

        void Breakthrough::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -50), battleField, crited, 100);
            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::minDamage), -10},
            {static_cast<int>(Characteristic::maxDamage), -10},
            {static_cast<int>(Characteristic::speed), -1}}), battleField, crited, 100);
        }

        void Breakthrough::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string Breakthrough::getEffectDescription() {
            return "Damage -50% ";
        }
        std::string Breakthrough::getSelfDescription() {
            return "Forward 1 -10% DMG -1 SPD (3 rds)";
        }
    } // namespace Hellion
} // namespace Heroes