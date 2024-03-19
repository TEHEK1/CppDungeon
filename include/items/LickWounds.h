//
// Created by kait on 3/19/24.
//
#include "items/Item.h"
#include "skillDesigns/RangeSkill.h"

#ifndef UGABUGA_LICKWOUNDS_H
#define UGABUGA_LICKWOUNDS_H
namespace items {
    namespace LickWounds {
        class LickWounds : public skillDesigns::RangeSkill {
        public:
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            LickWounds();
        };
    } // namespace LickWounds
} // namespace items
#endif //UGABUGA_LICKWOUNDS_H
