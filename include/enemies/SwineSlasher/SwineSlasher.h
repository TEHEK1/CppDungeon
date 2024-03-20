#ifndef SwineSlasher_H
#define SwineSlasher_H
#include "entity/Enemy.h"
#include "enemies/SwineSlasher/HookWhereItHurts.h"

namespace enemies {
    namespace SwineSlasher {
        class SwineSlasher : public entity::Enemy {
        public:
            std::vector<std::vector<char>> drawAlive() override;

            SwineSlasher();
        };
    } // namespace SwineSlasher
} // namespace enemies
#endif //SwineSlasher_H