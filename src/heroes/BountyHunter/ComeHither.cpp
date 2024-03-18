#include "heroes/BountyHunter/ComeHither.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace BountyHunter {
        ComeHither::ComeHither() : RangeSkill(1, "ComeHither", {1, 2, 3, 4}, {}, {3, 4}, 90, 0) {}

        void ComeHither::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 7, 15), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
            (crited, 3, 3), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Mark>
            (crited, 3), battleField, crited, 100);
        }

        void ComeHither::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies