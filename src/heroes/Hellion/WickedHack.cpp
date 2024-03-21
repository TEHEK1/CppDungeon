#include "heroes/Hellion/WickedHack.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Hellion {
        WickedHack::WickedHack(): skillDesigns::RangeSkill(1, "WickedHack", {1, 2}, {}, {1, 2}, 85, 4) {}

        void WickedHack::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, 0), battleField, crited, 100);
        }

        void WickedHack::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string WickedHack::getEffectDescription() {
            return "Damage 0% ";
        }
        std::string WickedHack::getSelfDescription() {
            return "";
        }
    } // namespace Hellion
} // namespace Heroes