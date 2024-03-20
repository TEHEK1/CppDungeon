//
// Created by kait on 3/20/24.
//

#ifndef UGABUGA_GHOUL_H
#define UGABUGA_GHOUL_H
#include "entity/Enemy.h"
#include "enemies/Ghoul/Howl.h"
#include "enemies/Ghoul/Rend.h"
#include "enemies/Ghoul/SkullToss.h"
namespace enemies {
    namespace Ghoul {
        class Ghoul : public entity::Enemy {
        public:
            std::vector<std::vector<char>> drawAlive() override;

            Ghoul();
        };
    } // namespace Ghoul
} // namespace enemies
#endif //UGABUGA_GHOUL_H
