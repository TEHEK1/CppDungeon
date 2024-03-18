#include "enemies/BrigandRaider/Shank.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace enemies {
    namespace BrigandRaider {
        Shank::Shank() : RangeSkill(1, "Shank", {1, 2, 3}, {}, {1, 2, 3, 4}, 93, 11) {}

        void Shank::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 7, 15), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
            (crited, 3, 3), battleField, crited, 140);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Marked>
            (crited, 3), battleField, crited, 100);
        }

        void Shank::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies