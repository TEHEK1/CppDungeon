#ifndef RENDFORTHEOLDGODS_H
#define RENDFORTHEOLDGODS_H
#include "skillDesigns/RangeSkill.h"
namespace enemies {
    namespace CultistBrawler {
        class RendForTheOldGods : public skillDesigns::RangeSkill {
        public:
            RendForTheOldGods();

            void unsafeTargetUse(int crited, std::shared_ptr <BattleField> battleField,
                                 std::shared_ptr <entity::Entity> actor,
                                 std::shared_ptr <entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr <BattleField> battleField,
                               std::shared_ptr <entity::Entity> object) override;
        };
    } // namespace CultistBrawler
} // namespace enemies
#endif //RENDFORTHEOLDGODS_H