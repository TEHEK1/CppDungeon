#include "enemies/PelagicGrouper/SeawardSlash.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Move.h"
namespace enemies {
    namespace PelagicGrouper {
        SeawardSlash::SeawardSlash(): skillDesigns::RangeSkill(1, "Seaward Slash", {1, 2}, {}, {1, 2}, 78, 2) {}

        void SeawardSlash::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                          std::shared_ptr<entity::Entity> actor,
                                          std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 5, 9), battleField, crited, 100);

        }
        void SeawardSlash::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                       std::shared_ptr<entity::Entity> object) {
                                        
        }
    } // namespace PelagicGrouper
} // namespace enemies