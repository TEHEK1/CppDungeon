#ifndef STUMBLINGSCRATCH_H
#define STUMBLINGSCRATCH_H
#include "skillDesigns/RangeSkill.h"
namespace enemies {
    namespace CultistBrawler {
        class StumblingScratch : public skillDesigns::RangeSkill {
        public:
            StumblingScratch();

            void unsafeTargetUse(int crited, std::shared_ptr <BattleField> battleField,
                                 std::shared_ptr <entity::Entity> actor,
                                 std::shared_ptr <entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr <BattleField> battleField,
                               std::shared_ptr <entity::Entity> object) override;
        };
    } // namespace CultistBrawler
} // namespace enemies
#endif //STUMBLINGSCRATCH_H