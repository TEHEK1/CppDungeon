#include <memory>
#include "BattleField.h"

class MarkedAsAutoTurn {
public:
    virtual void autoTurn(std::shared_ptr<BattleField> battlefield) = 0;
};
