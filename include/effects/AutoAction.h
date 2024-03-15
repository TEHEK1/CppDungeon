//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_AUTOACTION_H
#define CPPDUNGEON_AUTOACTION_H
#include "effects/Buff.h"
#include "effects/MarkedAsEntityNeeded.h"
namespace effects {
    class AutoAction : public Effect, public changers::EntityChanger, public MarkedAsEntityNeeded, public MarkedAsTurnable{
        std::map<int, int> m_turner;
    public:
        ~AutoAction() override = default;
        AutoAction(int numberOfTurns, const std::map<int, int>& turner);
        std::map<int, int> getTurner();
    protected:
        std::function<int(std::shared_ptr<entity::Entity>)> getTurnFunction() override;//TODO: Leave just here
    };
}
#endif //CPPDUNGEON_AUTOACTION_H
