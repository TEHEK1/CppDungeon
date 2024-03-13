//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_AUTOACTION_H
#define CPPDUNGEON_AUTOACTION_H
#include "effects/Effect.h"
namespace effects {
    class AutoAction : public Effect {
        std::map<size_t, int> m_turner;
        int m_numberOfTurns;
        int m_crited;
        int m_critModifier = 150;
    public:
        AutoAction(std::weak_ptr<Entity>, int numberOfTurns, std::map<size_t, int> modifier, std::map<size_t, int> turner, int crited, int critModifier = 150);
        int getRemainingTurns();
        int getTurner();
        void turn();
        virtual void endBattleTurn();
    };
}
#endif //CPPDUNGEON_AUTOACTION_H
