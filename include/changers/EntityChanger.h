//
// Created by Владимир Попов on 09.03.2024.
//

#ifndef ENTITY_CHANGER_H
#define ENTITY_CHANGER_H

#include "entity/Characteristic.h"
#include "EffectChanger.h"
#include <memory>
#include "namespaces/entity.h"
class Skill;
namespace changers {
    class EntityChanger{
    protected:
        static void set(std::shared_ptr<entity::Entity> entity, Characteristic characteristic, int value);
        static void set(std::shared_ptr<entity::Entity> entity, int characteristic, int value);

        static void addSkill(std::shared_ptr<entity::Entity> entity, std::shared_ptr<Skill> skill);
        static void removeSkill(std::shared_ptr<entity::Entity> entity, std::shared_ptr<Skill> skill);
    };
} // namespace changers
#endif // ENTITY_CHANGER_H
