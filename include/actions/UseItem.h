//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_USEITEM_H
#define CPPDUNGEON_USEITEM_H
#include "actions/Action.h"
#include <vector>
#include <memory>
#include "namespaces/entity.h"
#include "namespaces/items.h"
namespace actions {
    class UseItem : public Action {
    public:
        UseItem(Player *player, items::Item *item, std::vector<std::shared_ptr<entity::Entity>> entities);

        void act(Player *) override;
        std::string getName() override;
    };
} // namespace actions
#endif //CPPDUNGEON_USEITEM_H
