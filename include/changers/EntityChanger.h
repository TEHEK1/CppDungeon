//
// Created by Владимир Попов on 09.03.2024.
//

#ifndef ENTITY_CHANGER_H
#define ENTITY_CHANGER_H

#include "entity/Characteristic.h"
#include <memory>
class Entity;
namespace effects{
    class Effect;
} // namespace effects
class Skill;
namespace changers {
    class EntityChanger {
    protected:
        static void set(std::shared_ptr<Entity> entity, Characteristic characteristic, int value);

        static void set(std::shared_ptr<Entity> entity, size_t characteristic, int value);

        static void turnEffects(std::shared_ptr<Entity> entity);

        static void endBattleTurnEffects(std::shared_ptr<Entity> entity);

        static void addEffect(std::shared_ptr<Entity> entity, std::shared_ptr<effects::Effect> effect);

        static void removeEffect(std::shared_ptr<Entity> entity, std::shared_ptr<effects::Effect> effect);

        static void addSkill(std::shared_ptr<Entity> entity, std::shared_ptr<Skill> skill);

        static void removeSkill(std::shared_ptr<Entity> entity, std::shared_ptr<Skill> skill);
    };
} // namespace changers
#endif // ENTITY_CHANGER_H