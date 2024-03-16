//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_AUTOACTION_H
#define CPPDUNGEON_AUTOACTION_H
#include "effects/Buff.h"
#include "effects/MarkedAsEntityNeeded.h"
#include "effects/MarkedAsTurnable.h"
#include "effects/MarkedAsEndBattle.h"
namespace effects {
    class AutoAction : public Effect, public changers::EntityChanger, public MarkedAsEntityNeeded, public MarkedAsTurnable, public MarkedAsEndBattle{
        std::map<int, int> m_turner;
    public:
        ~AutoAction() override = default;
        AutoAction(int numberOfTurns, const std::map<int, int>& turner);
        std::map<int, int> getTurner();
    protected:
        std::function<int()> getTurnFunction() override;
        std::function<int(const std::shared_ptr<entity::Entity>& )> getTurnFunctionEntity() override;

    };
}
#endif //CPPDUNGEON_AUTOACTION_H
