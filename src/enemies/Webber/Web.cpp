#include "enemies/Webber/Web.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Debuff.h"
#include "effects/Stun.h"
#include "effects/Mark.h"
namespace enemies {
    namespace Webber {
        Web::Web() : RangeSkill(1, "Web", {1, 2, 3, 4}, {}, {1, 2, 3, 4}, 83, 6) {}

        void Web::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> actor,
                                  std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
                    (crited, 1, 1), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Stun>
                    (crited, 3), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Mark>
                    (crited, 3), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
                    (crited, 3, std::map<int, int>{{static_cast<int>(Resistances::Blight),-15}}), battleField, crited, 100);

        }

        void Web::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies