//
// Created by kait on 3/20/24.
//
#ifndef UGABUGA_HOWL_H
#define UGABUGA_HOWL_H
#include "skillDesigns/RangeSkill.h"

namespace enemies {
    namespace Ghoul {
        class Howl : public skillDesigns::RangeSkill {
        public:
            Howl();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    } // namespace Ghoul
} // namespace enemies
#endif //UGABUGA_HOWL_H
