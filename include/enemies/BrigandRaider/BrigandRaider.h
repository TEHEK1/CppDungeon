//
// Created by Владимир Попов on 14.03.2024
//
#ifndef UNTITLED_BRIGANDRAIDER_H
#define UNTITLED_BRIGANDRAIDER_H
#include "entity/Enemy.h"

namespace enemies {
    namespace BrigandRaider {
        class BrigandRaider : public entity::Enemy {
        public:
            std::vector<std::vector<char>> drawAlive() override;

            BrigandRaider();
        };
    } // namespace BrigandRaider
} // namespace enemies
#endif //BRIGANDRAIDER_H