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
protected:
    void set(std::shared_ptr<Entity> entity, Characteristic characteristic, int value);
    void set(std::shared_ptr<Entity> entity, size_t characteristic, int value);
    void turnEffects(std::shared_ptr<Entity> entity);
    void endBattleTurnEffects(std::shared_ptr<Entity> entity);
    void addEffect(std::shared_ptr<Entity> entity, std::shared_ptr<effects::Effect> effect);
    void removeEffect(std::shared_ptr<Entity> entity, std::shared_ptr<effects::Effect> effect);
    void addSkill(std::shared_ptr<Entity> entity, std::shared_ptr<Skill> skill);
    void removeSkill(std::shared_ptr<Entity> entity, std::shared_ptr<Skill> skill);
};

#endif // ENTITY_CHANGER_H
