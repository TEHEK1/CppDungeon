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
    class EntityChanger: public EffectChanger{
    protected:
        static void set(std::shared_ptr<entity::Entity> entity, Characteristic characteristic, int value);

        static void set(std::shared_ptr<entity::Entity> entity, size_t characteristic, int value);

        static void turnEffects(std::shared_ptr<entity::Entity> entity);

        static void endBattleTurnEffects(std::shared_ptr<entity::Entity> entity);

        static void addEffect(std::shared_ptr<entity::Entity> entity, std::shared_ptr<effects::Effect> effect);

        static void removeEffect(std::shared_ptr<entity::Entity> entity, std::shared_ptr<effects::Effect> effect);

        static void addSkill(std::shared_ptr<entity::Entity> entity, std::shared_ptr<Skill> skill);

        static void removeSkill(std::shared_ptr<entity::Entity> entity, std::shared_ptr<Skill> skill);
    };
} // namespace changers
#endif // ENTITY_CHANGER_H
