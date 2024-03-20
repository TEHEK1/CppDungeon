//
// Created by kait on 3/20/24.
//

#ifndef UGABUGA_REND_H
#define UGABUGA_REND_H
#include "skillDesigns/RangeSkill.h"

namespace enemies {
    namespace Ghoul {
        class Rend : public skillDesigns::RangeSkill {
        public:
            Rend();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    } // namespace Ghoul
} // namespace enemies

#endif //UGABUGA_REND_H
