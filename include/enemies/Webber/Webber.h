#ifndef UNTITLED_Webber_H
#define UNTITLED_Webber_H
#include "entity/Enemy.h"
#include "enemies/Webber/Webber.h"
#include "enemies/Webber/Bite.h"
#include "enemies/Webber/Web.h"

namespace enemies {
    namespace Webber {
        class Webber : public entity::Enemy {
        public:
            std::vector<std::vector<char>> drawAlive() override;

            Webber();
        };
    } // namespace Webber
} // namespace enemies
#endif //Webber_H