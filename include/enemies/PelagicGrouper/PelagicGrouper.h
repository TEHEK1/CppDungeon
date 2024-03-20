#ifndef UNTITLED_PelagicGrouper_H
#define UNTITLED_PelagicGrouper_H
#include "entity/Enemy.h"
#include "enemies/PelagicGrouper/SeawardSlash.h"
#include "enemies/PelagicGrouper/Spearfishing.h"

namespace enemies {
    namespace PelagicGrouper {
        class PelagicGrouper : public entity::Enemy {
        public:
            std::vector<std::vector<char>> drawAlive() override;

            PelagicGrouper();
        };
    } // namespace PelagicGrouper
} // namespace enemies
#endif //PelagicGrouper_H