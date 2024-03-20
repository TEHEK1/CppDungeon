#ifndef UNTITLED_RabidGnasher_H
#define UNTITLED_RabidGnasher_H
#include "entity/Enemy.h"
#include "enemies/RabidGnasher/RabidRush.h"

namespace enemies {
    namespace RabidGnasher {
        class RabidGnasher : public entity::Enemy {
        public:
            std::vector<std::vector<char>> drawAlive() override;

            RabidGnasher();
        };
    } // namespace RabidGnasher
} // namespace enemies
#endif //RabidGnasher_H