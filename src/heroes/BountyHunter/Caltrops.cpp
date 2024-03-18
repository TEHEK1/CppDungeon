#include "heroes/BountyHunter/Caltrops.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace BountyHunter {
        Caltrops::Caltrops() : RangeSkill(1, "Caltrops", {1, 2, 3}, {}, {3, 4}, 90, 5) {}

        void Caltrops::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(generators::EffectGenerator::generateHeroDamage<effects::Damage>(crited, actor, -95));
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
            (crited, 3, 2), battleField, crited, 100);
            Skill:addEffect(object, generators::EffectGenerator::)
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Mark>
            (crited, 3), battleField, crited, 100);
        }

        void Caltrops::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies