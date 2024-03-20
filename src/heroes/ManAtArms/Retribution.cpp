#include "heroes/ManAtArms/Retribution.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
#include "effects/Debuff.h"

namespace Heroes {
    namespace ManAtArms {
        Retribution::Retribution() : Skill("Retribution", {1, 2, 3}, {1, 2, 3}, {}, 85, 3) {}

        void Retribution::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -60), battleField, crited, 100);
            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
            (crited, 2, std::map<int, int>{{static_cast<int>(Characteristic::marked), 1},
            {static_cast<int>(Characteristic::minDamage), -40},
            {static_cast<int>(Characteristic::maxDamage), -40}}), battleField, crited, 100);
        }

        void Retribution::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace ManAtArms
} // namespace Heroes