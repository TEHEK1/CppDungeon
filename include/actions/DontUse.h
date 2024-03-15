//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_DONTUSE_H
#define CPPDUNGEON_DONTUSE_H

#include "actions/Action.h"
#include <memory>
class Trap;
class Chest;
namespace actions {
    class DontUse : public Action {
    public:
        explicit DontUse(const std::shared_ptr<Trap>&);
        void act(Player *player) override;
        std::shared_ptr<Trap> getTrap() const;
    private:
        std::shared_ptr<Trap> m_trap;
    };
}//namespace actions
#endif //CPPDUNGEON_DONTUSE_H