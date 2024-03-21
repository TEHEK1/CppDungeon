#include "heroes/Musketeer/Sidearm.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Musketeer {
        Sidearm::Sidearm(): skillDesigns::RangeSkill(1, "Sidearm", {1, 2, 3, 4}, {}, {1, 2, 3, 4}, 75, 0) {}

        void Sidearm::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -10), battleField, crited, 100);

            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::speed), 3}}), battleField, crited, 100);
        }

        void Sidearm::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string Sidearm::getEffectDescription() {
            return "Damage -10% ";
        }
        std::string Sidearm::getSelfDescription() {
            return "+3 SPD";
        }
    } // namespace Musketeer
} // namespace Heroes