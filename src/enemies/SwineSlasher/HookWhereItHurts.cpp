#include "enemies/SwineSlasher/HookWhereItHurts.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Bleed.h"
#include "effects/Move.h"
namespace enemies {
    namespace SwineSlasher {
        HookWhereItHurts::HookWhereItHurts(): RangeSkill(1, "HookWhereItHurts", {1, 2, 3, 4}, {}, {1, 2, 3}, 83, 16) {}

        void HookWhereItHurts::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                          std::shared_ptr<entity::Entity> actor,
                                          std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 3, 7), battleField, crited, 100);
            Skill::addEffect(actor, generators::EffectGenerator::generateUncritedEffect<effects::Move>
            (crited, 1), battleField, crited, 100);

        }
        void HookWhereItHurts::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                       std::shared_ptr<entity::Entity> object) {
                                        
        }
    } // namespace SwineSlasher
} // namespace enemies