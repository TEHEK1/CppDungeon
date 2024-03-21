#include "heroes/ManAtArms/Defender.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace ManAtArms {
        Defender::Defender(): skillDesigns::RangeSkill(1, "Defender", {1, 2, 3, 4}, {1, 2, 3, 4}, {}, 100, 0) {}

        void Defender::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 4, std::map<int, int>{{static_cast<int>(Characteristic::defence), 20}}), battleField, crited, 100);
        }

        void Defender::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string Defender::getEffectDescription() {
            return "Guard Ally";
        }
        std::string Defender::getSelfDescription() {
            return "+15% PROT";
        }
    } // namespace ManAtArms
} // namespace Heroes