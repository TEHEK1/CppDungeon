#include "heroes/Hellion/AdrenalineRush.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Heal.h"
#include "effects/Buff.h"
namespace Heroes {
    namespace Hellion {
        AdrenalineRush::AdrenalineRush() : RangeSkill(0, "AdrenalineRush", {1, 2, 3, 4}, {1, 2, 3, 4}, {}, 100, 0) {}

        void AdrenalineRush::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            
        }

        void AdrenalineRush::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Heal>
            (crited, 1, 1), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 4, std::map<int, int>{{static_cast<int>(Characteristic::accuracyModifier), 5},
            {static_cast<int>(Characteristic::minDamage), 20}, {static_cast<int>(Characteristic::maxDamage), 20}}), battleField, crited, 100);
            // TODO Cure Bleed and Blight
        }
    } // namespace Hellion
} // namespace Heroes