//
// Created by artem on 13.03.2024.
//
#include "effects/AutoAction.h"
#include "effects/Effect.h"
#include "entity/Entity.h"
#include "changers/EntityChanger.h"

namespace effects {
    AutoAction::AutoAction(int numberOfTurns, const std::map<int, int>& turner):
 m_turner(turner), MarkedAsTurnable(numberOfTurns) {}

    std::map<int, int> AutoAction::getTurner() {
        return m_turner;
    }
    std::function<int(std::shared_ptr<entity::Entity>)> AutoAction::getTurnFunction() {
        return [turn = this->MarkAsTurnable::getTurnFunction(), &turner = this->m_turner](std::shared_ptr<entity::Entity> object){
            for(auto &characteristic:turner){
                set(object, characteristic.first, object->getReal(characteristic.first) + characteristic.second);
            }
            return turn(object);};
    }
} // namespace effects