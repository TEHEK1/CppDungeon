#include "heroes/BountyHunter/ComeHither.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
#include "effects/ForceMove.h"
namespace Heroes {
    namespace BountyHunter {
        ComeHither::ComeHither() : RangeSkill(1, "ComeHither", {1, 2, 3, 4}, {}, {3, 4}, 90, 0) {}

        void ComeHither::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {

            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -80), battleField, crited, 100);

            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
            (crited, 2, std::map<int, int> {{static_cast<int>(Characteristic::marked), 1}}), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::ForceMove>
                    (crited, -2), battleField, crited, 100);
        }

        void ComeHither::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies