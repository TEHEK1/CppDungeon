//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H
#include "Entity.h"
class Enemy:public Entity{
public:
    Enemy(int accuracyModifier, int criticalDamagehance, int damage,
            int dodge, int defence, int speed, int HP);
};
#endif //UNTITLED_ENEMY_H
