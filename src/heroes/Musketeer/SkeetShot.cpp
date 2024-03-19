#include "heroes/Musketeer/Buckshot.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Buff.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Musketeer {
        Buckshot::Buckshot() : RangeSkill(2, "Buckshot", {3, 4}, {}, {1}, 95, 2) {}

        void Buckshot::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -80), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
            (crited, 3, 1), battleField, crited, 100);
            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::speed), 2}}), battleField, crited, 100);
        }

        void Buckshot::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace Musketeer
} // namespace Heroes