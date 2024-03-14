#include "Enemy.h"
#include "Entity.h"

Enemy::Enemy(int accuracyModifier, int criticalDamagehance, int damage,
            int dodge, int defence, int speed, int HP): Entity(accuracyModifier, 
            criticalDamagehance, damage, dodge, defence, speed, HP) {}