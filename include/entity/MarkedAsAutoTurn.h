#ifndef UNTITLED_MARKEDASAUTOTURN_H
#define UNTITLED_MARKEDASAUTOTURN_H
#include <memory>
#include "entity/Entity.h"
#include "player/Player.h"
class BattleField;
namespace entity {
    class MarkedAsAutoTurn{
    public:
        virtual void autoTurn(std::shared_ptr<Player>, std::shared_ptr<BattleField>, std::shared_ptr<entity::Entity>, int) = 0;
    };
};

#endif //UNTITLED_MARKEDASAUTOTURN_H