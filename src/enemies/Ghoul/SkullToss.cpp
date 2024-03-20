//
// Created by kait on 3/20/24.
//
#include "enemies/Ghoul/SkullToss.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Bleed.h"
#include "effects/Debuff.h"

namespace enemies {
    namespace Ghoul {
        SkullToss::SkullToss() : RangeSkill(1, "SkullToss", {1, 2, 3, 4}, {}, {3, 4}, 89, 12) {}

        void SkullToss::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                   std::shared_ptr<entity::Entity> actor,
                                   std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
                    (crited, 5, 11), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
                    (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::turnable),-1}}), battleField, crited, 100);
        }

        void SkullToss::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> object) {

        }
    } // namespace Ghoul
} // namespace enemies