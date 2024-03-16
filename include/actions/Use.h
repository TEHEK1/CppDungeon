//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_USE_H
#define CPPDUNGEON_USE_H
#include <memory>
#include "actions/Action.h"
class Chest;
namespace actions {
    class Use : public Action {
    public:
        explicit Use(const std::shared_ptr<Chest>&);
        void act(Player *player) override;
        std::shared_ptr<Chest> getChest();

    private:
        std::shared_ptr<Chest> m_chest;
    };

#endif //CPPDUNGEON_USE_H
}//namespace actions