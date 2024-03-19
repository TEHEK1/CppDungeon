#include "bosses/GardenGuardian/GardenGuardianDefenceBonus.h"
#include "generators/EffectGenerator.h"
#include "effects/Buff.h"
namespace Bosses {
    namespace StoneShield {
        GardenGuardianDefenceBonus::GardenGuardianDefenceBonus() : RangeSkill(4, "GardenGuardianDefenceBonus", {1, 2, 3, 4}, {1}, {}, 100, 0) {}

        void GardenGuardianDefenceBonus::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 2, std::map<int, int>{{static_cast<int>(Characteristic::defence), 10}}), battleField, crited, 100);
        }

        void GardenGuardianDefenceBonus::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {
            
        }
    } // namespace GardenGuardian
} // namespace Boss