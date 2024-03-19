//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_ABSINTHEEFFECT_H
#define UGABUGA_ABSINTHEEFFECT_H
#include "skillDesigns/Skill.h"
#include "skillDesigns/RangeSkill.h"
namespace items{
    namespace Absinthe{
        class AbsintheEffect : skillDesigns::RangeSkill{
        public:
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            AbsintheEffect();
        };
    }// namespace Absinthe
}//namespace items
#endif //UGABUGA_ABSINTHEEFFECT_H
