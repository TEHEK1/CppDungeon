//
// Created by kait on 3/19/24.
//
#include "generators/EffectGenerator.h"
#include "items/LickWounds.h"
#include "items/BloodiedNeckerchief.h"
#include "effects/PermanentEffect.h"
#include "entity/Characteristic.h"
namespace items {
    namespace BloodiedNeckerchief{
        BloodiedNeckerchiefEffect::BloodiedNeckerchiefEffect() : skillDesigns::RangeSkill(0, "Bloodied Neckerchief Effect", {1, 2, 3, 4},
                                                                                    {1, 2, 3, 4}, {}, 100) {}

        void BloodiedNeckerchiefEffect::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                                     std::shared_ptr<entity::Entity> actor,
                                                     std::shared_ptr<entity::Entity> object) {}

        void BloodiedNeckerchiefEffect::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                                   std::shared_ptr<entity::Entity> object) {
            skillDesigns::Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::PermanentEffect>
                    (crited, std::map<int, int>{{static_cast<int>(Characteristic::speed), 2},
                                                {static_cast<int>(Characteristic::dodge), 10}}), battleField, crited, 100);
        }
    } // namespace FortifyingGarlic
} // namespace items