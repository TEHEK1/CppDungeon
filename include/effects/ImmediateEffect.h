//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_IMMEDIATEEFFECT_H
#define CPPDUNGEON_IMMEDIATEEFFECT_H
#include "effects/AutoAction.h"
namespace effects {
    class ImmediateEffect:public AutoAction {
    public:
        ImmediateEffect(std::weak_ptr<Entity>, std::map<size_t, int> turner, int crited, int critModifier);
    };
}
#endif //CPPDUNGEON_IMMEDIATEEFFECT_H
