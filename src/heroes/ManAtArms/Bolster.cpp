#include "heroes/ManAtArms/Bolster.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace ManAtArms {
        Bolster::Bolster() : skillDesigns::RangeSkill(3, "Bolster", {1, 2, 3, 4}, {1, 2, 3, 4}, {}, 100) {}

        void Bolster::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            
            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 4, std::map<int, int>{{static_cast<int>(Characteristic::dodge), 5}}), battleField, crited, 100);
        }

        void Bolster::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string Bolster::getEffectDescription() {
            return "+5 DODGE -10% Stress";
        }
        std::string Bolster::getSelfDescription() {
            return "";
        }
    } // namespace ManAtArms
} // namespace Heroes