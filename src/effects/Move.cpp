//
// Created by artem on 13.03.2024.
//
#include "BattleField.h"
#include "effects/Move.h"
namespace effects {
    Move::Move(int offset) : m_offset(offset) {}

    std::function<int(const std::shared_ptr<entity::Entity>&, const std::shared_ptr<BattleField>&)>
    Move::getTurnFunctionBattleField() {
        return  [&offset = this->m_offset]
                (std::shared_ptr<entity::Entity> entity, const std::shared_ptr<BattleField>& battleField){
                relativeMove(battleField, entity, offset);
                return -1;};
    }
}