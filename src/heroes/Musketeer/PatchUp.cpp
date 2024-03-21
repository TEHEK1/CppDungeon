#include "heroes/Musketeer/PatchUp.h"
#include "generators/EffectGenerator.h"
#include "generators/NumberGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Heal.h"
namespace Heroes {
    namespace Musketeer {
        PatchUp::PatchUp(): skillDesigns::RangeSkill(1, "PatchUp", {3, 4}, {1, 2, 3, 4}, {}, 100, 0) {}

        void PatchUp::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Heal>
                    (crited, 1, 2 + generators::NumberGenerator::generate(0, 1)), battleField, crited, 100);
        }

        void PatchUp::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
        std::string PatchUp::getEffectDescription() {
            return "+20% Healing";
        }
        std::string PatchUp::getSelfDescription() {
            return "";
        }
    } // namespace Musketeer
} // namespace Heroes