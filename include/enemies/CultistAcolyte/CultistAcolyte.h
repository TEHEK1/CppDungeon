//
// Created by Владимир Попов on 14.03.2024
//
#ifndef UNTITLED_CULTISTACOLYTE_H
#define UNTITLED_CULTISTACOLYTE_H
#include "entity/Enemy.h"
#include "enemies/CultistAcolyte/EldritchPush.h"
#include "enemies/CultistAcolyte/EldritchPull.h"
#include "enemies/CultistAcolyte/StressfulIncantation.h"
namespace enemies {
    namespace CultistAcolyte {
        class CultistAcolyte : public entity::Enemy {
        public:
            std::vector<std::vector<char>> drawAlive() override;

            CultistAcolyte();
        };
    } // namespace CultistAcolyte
} // namespace enemies
#endif //CULTISTACOLYTE_H