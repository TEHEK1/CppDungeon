//
// Created by kait on 3/20/24.
//

#ifndef UGABUGA_CULTISTBRAWLER_H
#define UGABUGA_CULTISTBRAWLER_H
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
#endif //UGABUGA_CULTISTBRAWLER_H
