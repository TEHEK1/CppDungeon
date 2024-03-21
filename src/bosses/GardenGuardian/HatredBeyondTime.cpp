#include "bosses/GardenGuardian/HatredBeyondTime.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Heal.h"
#include "effects/Bleed.h"
#include "effects/Blight.h"
namespace Bosses {
    namespace GardenGuardian {
        HatredBeyondTime::HatredBeyondTime() : skillDesigns::RangeSkill(1, "HatredBeyondTime", {1, 2, 3, 4}, {1, 2, 3, 4}, {}, 100, 0) {}

        void HatredBeyondTime::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            
        }

        void HatredBeyondTime::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Heal>
            (crited, 1, 1), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 5, std::map<int, int>{{static_cast<int>(Characteristic::accuracyModifier), 5},
            {static_cast<int>(Characteristic::minDamage), 10}, {static_cast<int>(Characteristic::maxDamage), 10},
            {static_cast<int>(Characteristic::criticalDamageChance), 3}}), battleField, crited, 100);
        }

    } // namespace GardenGuardian
} // namespace Boss