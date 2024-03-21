#include "heroes/Hellion/IfItBleeds.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Hellion {
        IfItBleeds::IfItBleeds() : skillDesigns::RangeSkill(1, "IfItBleeds", {1, 2, 3}, {}, {2, 3}, 85, -1) {}

        void IfItBleeds::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -35), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
            (crited, 3, 2), battleField, crited, 100);
        }

        void IfItBleeds::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string IfItBleeds::getEffectDescription() {
            return "Damage -35%\nBleed (100% base)\n2 pts/rd for 3 rds";
        }
        std::string IfItBleeds::getSelfDescription() {
            return "";
        }
    } // namespace Hellion
} // namespace Heroes