#include "entity/Entity.h"
#include "heroes/BountyHunter/BountyHunter.h"
#include "enemies/BrigandFusilier/BrigandFusilier.h"

#include "BattleField.h"
#include "Squad.h"
#include "effects/ForceMove.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include "changers/EffectChanger.h"
#include "generators/EffectGenerator.h"
#include <memory>
#include "generators/SkillActionsGenerator.h"
class EffectChangerAdapter: public changers::EffectChanger{
public:
    using changers::EffectChanger::addEffect;
};

int main() {
    
    std::vector<std::shared_ptr<entity::Entity>> allies;
    for(int i = 0;i<4;i++){
        allies.push_back(std::make_shared<Heroes::BountyHunter::BountyHunter>());
    }
    std::vector<std::shared_ptr<entity::Entity>> enemies;
    for(int i = 4;i<8;i++){
        enemies.push_back(std::make_shared<enemies::BrigandFusilier::BrigandFusilier>());
    }
    std::shared_ptr<BattleField> battleField =
            std::make_shared<BattleField>(std::make_shared<Squad>(allies), std::make_shared<Squad>(enemies));
    auto skill = std::make_shared<Heroes::BountyHunter::MarkForDeath>();
    auto skillUses = generators::SkillActionsGenerator::generateAvailableUseSkills(skill,
            battleField, allies[1]);
    for(auto skillUse:skillUses){
        std::cout<<skillUse->getName()<<"\n";
    }
    std::cout<<"Usable "<<skill->isUsable(battleField, allies[1], {enemies[0]})<<"\n";

    return 0;
}