#ifndef CULTISTBRAWLER_H
#define CULTISTBRAWLER_H
#include "entity/Enemy.h"
#include "enemies/CultistBrawler/RendForTheOldGods.h"
#include "enemies/CultistBrawler/StumblingScratch.h"

namespace enemies {
    namespace CultistBrawler {
        class CultistBrawler : public entity::Enemy {
        public:
            std::vector<std::vector<char>> drawAlive() override;

            CultistBrawler();
        };
    } // namespace CultistBrawler
} // namespace enemies
#endif //CULTISTBRAWLER_H