#include "enemies/Ghoul/Rend.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Bleed.h"
namespace enemies {
    namespace Ghoul {
        Rend::Rend() : RangeSkill(2, "Rend", {1, 2}, {}, {1, 2}, 89, 16) {}

        void Rend::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                           std::shared_ptr<entity::Entity> actor,
                                           std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
                    (crited, 4, 8), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
                    (crited, 3, 2), battleField, crited, 120);
        }

        void Rend::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                         std::shared_ptr<entity::Entity> object) {

        }
    } // namespace Ghoul
} // namespace enemies