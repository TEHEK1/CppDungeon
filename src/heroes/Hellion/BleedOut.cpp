#include "heroes/Hellion/BleedOut.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Hellion {
        BleedOut::BleedOut() : skillDesigns::RangeSkill(1, "BleedOut", {1}, {}, {1}, 85, 6) {}

        void BleedOut::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {

            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, 20), battleField, crited, 100);

            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
            (crited, 3, 3), battleField, crited, 100);

            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::minDamage), -20},
            {static_cast<int>(Characteristic::maxDamage), -20},
            {static_cast<int>(Characteristic::speed), -3}}), battleField, crited, 100);
            
        }

        void BleedOut::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }

        std::string BleedOut::getEffectDescription() {
            return "Damage 20%\nBleed (100% base)\n3 pts/rd for 3 rds";
        }
        std::string BleedOut::getSelfDescription() {
            return "-20% DMG\n-3 SPD\n(3 rds)";
        }
    } // namespace Hellion
} // namespace Heroes