#include "heroes/Hellion/IronSwan.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Hellion {
        IronSwan::IronSwan(): skillDesigns::RangeSkill(1, "IronSwan", {1}, {}, {4}, 85, 5) {}

        void IronSwan::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {

            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, 0), battleField, crited, 100);
            
        }

        void IronSwan::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string IronSwan::getEffectDescription() {
            return "Damage 0% ";
        }
        std::string IronSwan::getSelfDescription() {
            return "";
        }
    } // namespace Hellion
} // namespace Heroes