//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_HERO_H
#define UNTITLED_HERO_H
#include "Entity.h"

class Hero:public Entity{
private:
    int m_damageMin;
    int m_damageMax;
public:
    int get(Characteristic characteristic) const override {
        if (characteristic == Characteristic::minDamage) {
            return m_damageMin;
        } else if (characteristic == Characteristic::maxDamage) {
            return m_damageMax;
        }

        return Entity::get(characteristic);
    }
};
#endif //UNTITLED_HERO_H
