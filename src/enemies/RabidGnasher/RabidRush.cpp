#include "enemies/RabidGnasher/RabidRush.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Bleed.h"
#include "effects/Move.h"
namespace enemies {
    namespace RabidGnasher {
        RabidRush::RabidRush(): skillDesigns::RangeSkill(1, "RabidRush", {1, 2, 3, 4}, {}, {1, 2, 3, 4}, 83, 16) {}

        void RabidRush::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                          std::shared_ptr<entity::Entity> actor,
                                          std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 2, 4), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
            (crited, 3, 1), battleField, crited, 100);
            Skill::addEffect(actor, generators::EffectGenerator::generateUncritedEffect<effects::Move>
            (crited, -3), battleField, crited, 100);

        }
        void RabidRush::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                       std::shared_ptr<entity::Entity> object) {
                                        
        }
    } // namespace RabidGnasher
} // namespace enemies