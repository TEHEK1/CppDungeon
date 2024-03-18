#include "enemies/BrigandRaider/HarmlessPoke.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Move.h"
#include "effects/Buff.h"
namespace enemies {
    namespace BrigandRaider {
        HarmlessPoke::HarmlessPoke() : RangeSkill(1, "Harmless Poke", {4}, {}, {1, 2, 3, 4}, 63, 0) {}

        void HarmlessPoke::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                           std::shared_ptr<entity::Entity> actor,
                                           std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
                    (crited, 4, 9), battleField, crited, 100);

        }

        void HarmlessPoke::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                         std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::Move>
            (crited, -1), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::speed),2}}), battleField, crited, 100);
        }
    } // namespace BrigandFusilier
} // namespace enemies