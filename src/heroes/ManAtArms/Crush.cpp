#include "heroes/ManAtArms/Crush.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace ManAtArms {
        Crush::Crush(): skillDesigns::RangeSkill(1, "Crush", {1, 2}, {}, {1, 2, 3}, 85, 5) {}

        void Crush::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, 0), battleField, crited, 100);
        }

        void Crush::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string Crush::getEffectDescription() {
            return "Damage +0%\n";
        }
        std::string Crush::getSelfDescription() {
            return "";
        }
    } // namespace ManAtArms
} // namespace Heroes