//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_USE_H
#define CPPDUNGEON_USE_H
#include <memory>
#include "actions/Action.h"
namespace events {
    class UsableEvent;
} // namespace events
namespace actions {
    class Use : public Action {
    public:
        explicit Use(const std::shared_ptr<events::UsableEvent>&);
        void act(Player *player) override;
        std::shared_ptr<events::UsableEvent> getChest();

    private:
        std::shared_ptr<events::UsableEvent> m_usableEvent;
    };

#endif //CPPDUNGEON_USE_H
}//namespace actions