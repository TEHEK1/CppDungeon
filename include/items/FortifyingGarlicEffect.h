//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_FORTIFYINGGARLICEFFECT_H
#define UGABUGA_FORTIFYINGGARLICEFFECT_H
#include "skillDesigns/Skill.h"
#include "skillDesigns/RangeSkill.h"
namespace items{
    namespace FortifyingGarlic{
        class FortifyingGarlicEffect : skillDesigns::RangeSkill{
        public:
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            FortifyingGarlicEffect();
        };
    }// namespace FortifyingGarlic
}//namespace items

#endif //UGABUGA_FORTIFYINGGARLICEFFECT_H
