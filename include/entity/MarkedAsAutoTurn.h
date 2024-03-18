#ifndef UNTITLED_MARKEDASAUTOTURN_H
#define UNTITLED_MARKEDASAUTOTURN_H
#include <memory>
#include "entity/Entity.h"
#include "player/Player.h"
class BattleField;
namespace entity {
    class MarkedAsAutoTurn{
    public:
        void autoTurn(std::shared_ptr<Player>, std::shared_ptr<BattleField>, std::shared_ptr<entity::Entity>, int);
    };
};

#endif //UNTITLED_MARKEDASAUTOTURN_H