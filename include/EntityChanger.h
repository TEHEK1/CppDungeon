//
// Created by Владимир Попов on 09.03.2024.
//

#ifndef ENTITY_CHANGER_H
#define ENTITY_CHANGER_H

#include <memory>
#include "Entity.h"
#include "Effect.h"
#include "Skill.h"

class Entity;

class EntityChanger {
private:
    Entity* m_entity;

public:
    EntityChanger(Entity* entity);

    void set(Characteristic characteristic, int value);
    void turnEffects();
    void endBattleTurnEffects();
    void addEffect(std::shared_ptr<Effect> effect);
    void removeEffect(std::shared_ptr<Effect> effect);
    void addSkill(std::shared_ptr<Skill> skill);
    void removeSkill(std::shared_ptr<Skill> skill);
};

#endif // ENTITY_CHANGER_H
