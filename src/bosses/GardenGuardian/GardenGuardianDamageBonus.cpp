#include "bosses/GardenGuardian/GardenGuardianDamageBonus.h"
#include "generators/EffectGenerator.h"
#include "effects/Buff.h"
namespace Bosses {
    namespace BloodFount {
        GardenGuardianDamageBonus::GardenGuardianDamageBonus() : skillDesigns::RangeSkill(4, "GardenGuardianDamageBonus", {1, 2, 3, 4}, {1}, {}, 100, 0) {}

        void GardenGuardianDamageBonus::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 2, std::map<int, int>{{static_cast<int>(Characteristic::minDamage), 10},
            {static_cast<int>(Characteristic::maxDamage), 10}}), battleField, crited, 100);
        }

        void GardenGuardianDamageBonus::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {
            
        }
    } // namespace GardenGuardian
} // namespace Boss