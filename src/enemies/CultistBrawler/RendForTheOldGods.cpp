#include "enemies/CultistBrawler/RendForTheOldGods.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
#include "effects/ForceMove.h"
#include "effects/Move.h"

namespace enemies {
    namespace CultistBrawler {
        RendForTheOldGods::RendForTheOldGods() : skillDesigns::RangeSkill(1, "RendForTheOldGods", {1, 2}, {}, {1, 2}, 73, 12) {}

        void RendForTheOldGods::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
                    (crited, 3, 5), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
                    (crited, 3, 1), battleField, crited, 100);
            Skill::addEffect(actor, generators::EffectGenerator::generateUncritedEffect<effects::Move>
                    (crited, -1), battleField, crited, 100);
        }

        void RendForTheOldGods::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace CultistBrawler
} // namespace enemies