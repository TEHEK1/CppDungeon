#include "heroes/BountyHunter/CollectBounty.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
#include "entity/EnemyType.h"
#include "skillDesigns/RangeSkill.h"

namespace Heroes {
    namespace BountyHunter {
        CollectBounty::CollectBounty() : skillDesigns::RangeSkill(1, "CollectBounty", {1, 2, 3}, {}, {1, 2}, 85, 7) {}

        void CollectBounty::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            int attackModifier = 0;
            if (object->get(Characteristic::marked) > 0) {
                attackModifier += 90;
            }
            if (object->get(Characteristic::enemyType) == static_cast<int>(EnemyType::Human)) {
                attackModifier += 15;
            }

            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, attackModifier), battleField, crited, 100);

        }

        void CollectBounty::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string CollectBounty::getEffectDescription() {
            return "Damage 0%\n+90% DMG vs Marked\n+15% DMG vs Human";
        }
        std::string CollectBounty::getSelfDescription() {
            return "";
        }
    } // namespace BrigandFusilier
} // namespace enemies