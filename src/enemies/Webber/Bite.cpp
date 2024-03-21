#include "enemies/Webber/Bite.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "entity/Entity.h"
#include "effects/Blight.h"
namespace enemies {
    namespace Webber {
        Bite::Bite() : skillDesigns::RangeSkill(1, "Bite", {1, 2, 3, 4}, {}, {1,2,3,4}, 73, 2) {}

        void Bite::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                   std::shared_ptr<entity::Entity> actor,
                                   std::shared_ptr<entity::Entity> object) {
            int damageModifier = (static_cast<int>(object->get(Characteristic::marked)>0)*100 + 100) / 100;
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
                    (crited, 1*damageModifier, 3*damageModifier), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Blight>
                    (crited, 3, 1), battleField, crited, 100);

        }

        void Bite::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> object) {

        }
    } // namespace BrigandFusilier
} // namespace enemies