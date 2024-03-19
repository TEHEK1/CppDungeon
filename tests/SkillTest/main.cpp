#include "entity/Entity.h"
#include "enemies/BrigandFusier/BrigandFusilier.h"
#include "enemies/BrigandRaider/BrigandRaider.h"

#include "BattleField.h"
#include "Squad.h"
#include "effects/ForceMove.h"
#include <iostream>
#include <cstdio>
#include "changers/EffectChanger.h"
#include "generators/EffectGenerator.h"
class EffectChangerAdapter: public changers::EffectChanger{
public:
    using changers::EffectChanger::addEffect;
};
int main() {
    std::vector<std::shared_ptr<entity::Entity>> allies;
    for(int i = 0;i<4;i++){
        allies.push_back(std::make_shared<enemies::BrigandRaider::BrigandRaider>());
    }
    std::vector<std::shared_ptr<entity::Entity>> enemies;
    for(int i = 4;i<8;i++){
        enemies.push_back(std::make_shared<enemies::BrigandFusilier::BrigandFusilier>());
    }
    std::shared_ptr<BattleField> battleField =
            std::make_shared<BattleField>(std::make_shared<Squad>(allies), std::make_shared<Squad>(enemies));
    std::cout<<"Usable "<<allies[0]->getSkills().begin()->get()->isUsable(battleField, allies[1], {enemies[1]})<<"\n";
    //EffectChangerAdapter::addEffect(allies[0], generators::EffectGenerator::generateUncritedEffect<effects::ForceMove>(1, 1), battleField);
    allies[0]->getSkills().begin()->get()->use(battleField, allies[1], {enemies[1]});
    for(auto i:battleField->getEntities()){
        std::cout<<i->getName()<<" ";
    }
    for(auto i:battleField->getEntities()){
        std::cout<<i->get(Characteristic::HP)<<" ";
    }
    return 0;
}