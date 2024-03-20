#include "enemies/PelagicGrouper/Spearfishing.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Move.h"
namespace enemies {
    namespace PelagicGrouper {
        Spearfishing::Spearfishing(): RangeSkill(1, "Spearfishing", {3, 4}, {}, {3, 4}, 78, 6) {}

        void Spearfishing::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                          std::shared_ptr<entity::Entity> actor,
                                          std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 3, 7), battleField, crited, 100);

        }
        void Spearfishing::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                       std::shared_ptr<entity::Entity> object) {
                                        
        }
    } // namespace PelagicGrouper
} // namespace enemies