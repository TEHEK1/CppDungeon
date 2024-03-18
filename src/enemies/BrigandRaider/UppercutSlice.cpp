#include "enemies/BrigandRaider/UppercutSlice.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/ForceMove.h"
namespace enemies {
    namespace BrigandRaider {
        UppercutSlice::UppercutSlice() : RangeSkill(1, "Uppercut Slice", {1, 2}, {}, {1, 2, 3}, 94, 15) {}

        void UppercutSlice::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                            std::shared_ptr<entity::Entity> actor,
                                            std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 4, 9), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::ForceMove>
            (crited, 1), battleField, crited, 140);

        }

        void UppercutSlice::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                          std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies