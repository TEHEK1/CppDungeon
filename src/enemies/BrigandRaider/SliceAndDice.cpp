#include "enemies/BrigandRaider/SliceAndDice.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Debuff.h"
namespace enemies {
    namespace BrigandRaider {
        SliceAndDice::SliceAndDice() : RangeSkill(2, "Slice And Dice", {1, 2, 3}, {}, {1, 2}, 94, 20) {}

        void SliceAndDice::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                           std::shared_ptr<entity::Entity> actor,
                                           std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 6, 11), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Resistances::Bleed),-35}}), battleField, crited, 160);

        }

        void SliceAndDice::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                         std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies