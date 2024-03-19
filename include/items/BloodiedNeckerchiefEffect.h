//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_BLOODIEDNECKERCHIEFEFFECT_H
#define UGABUGA_BLOODIEDNECKERCHIEFEFFECT_H
#include "skillDesigns/Skill.h"
#include "skillDesigns/RangeSkill.h"
namespace items{
    namespace BloodiedNeckerchief{
        class BloodiedNeckerchiefEffect : skillDesigns::RangeSkill{
        public:
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            BloodiedNeckerchiefEffect();
        };
    }// namespace BloodiedNeckerchief
}//namespace items
#endif //UGABUGA_BLOODIEDNECKERCHIEFEFFECT_H
