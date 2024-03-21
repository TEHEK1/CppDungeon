#include "heroes/ManAtArms/Rampart.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/ForceMove.h"
#include "effects/Debuff.h"
namespace Heroes {
    namespace ManAtArms {
        Rampart::Rampart(): skillDesigns::RangeSkill(1, "Rampart", {1, 2, 3}, {1, 2}, {}, 90, 5) {}

        void Rampart::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {

            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -60), battleField, crited, 100);

            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff> // TODO smth with stun
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::turnable), -1}}), battleField, crited, 100);

            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::ForceMove>
                    (crited, 1), battleField, crited, 100);

            Skill::addEffect(actor, generators::EffectGenerator::generateUncritedEffect<effects::Move>
                    (crited, -1), battleField, crited, 100);
        }

        void Rampart::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string Rampart::getEffectDescription() {
            return "Damage -60% Knockback 1 Stun ";
        }
        std::string Rampart::getSelfDescription() {
            return "Forward 1";
        }
    } // namespace ManAtArms
} // namespace Heroes