#ifndef UNTITLED_MARKEDASAUTOTURN_H
#define UNTITLED_MARKEDASAUTOTURN_H
#include <memory>
class BattleField;
namespace entity {
    class MarkedAsAutoTurn{
    public:
        void autoTurn(std::shared_ptr<BattleField>);
    };
};

#endif //UNTITLED_MARKEDASAUTOTURN_H