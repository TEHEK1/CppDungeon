//
// Created by kait on 3/19/24.
//
#include "generators/EffectGenerator.h"
#include "items/LickWounds.h"
#include "items/FortifyingGarlicEffect.h"
#include "effects/PermanentEffect.h"
namespace items {
    namespace FortifyingGarlic{
        FortifyingGarlicEffect::FortifyingGarlicEffect() : skillDesigns::RangeSkill(0, "Fortifying Garlic Effect", {1, 2, 3, 4},
                                                            {1, 2, 3, 4}, {}, 100) {}

        void FortifyingGarlicEffect::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                         std::shared_ptr<entity::Entity> actor,
                                         std::shared_ptr<entity::Entity> object) {}

        void FortifyingGarlicEffect::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                       std::shared_ptr<entity::Entity> object) {
            skillDesigns::Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::PermanentEffect>
                    (crited, std::map<int, int>{{static_cast<int>(Resistances::Bleed), 33},
                    {static_cast<int>(Resistances::Blight), 33}}), battleField, crited, 100);
        }
    } // namespace FortifyingGarlic
} // namespace items