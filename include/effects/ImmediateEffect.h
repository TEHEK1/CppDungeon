//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_IMMEDIATEEFFECT_H
#define CPPDUNGEON_IMMEDIATEEFFECT_H
#include "effects/AutoAction.h"
namespace effects {
    class ImmediateEffect:public Effect, public MarkedAsTurnable, public MarkedAsEntityNeeded {
    public:
        ~ImmediateEffect() override = default;
        ImmediateEffect();
    };
} // namespace effects
#endif //CPPDUNGEON_IMMEDIATEEFFECT_H
