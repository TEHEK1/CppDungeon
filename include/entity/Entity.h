//
// Created by Амир Кашапов on 24.02.2024.
//
#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H
#include <map>
#include <memory>
#include <set>
#include <string>

#include "skillDesigns/Skill.h"
#include "entity/Characteristic.h"
#include "effects/Effect.h"
#include "Resistances.h"

class Skill;
#include "namespaces/changers.h"
namespace entity {
    class Entity {
    protected:
        std::set<std::shared_ptr<Skill>> m_skills;
        std::map<int, int> m_characteristics;
        std::set<std::shared_ptr<effects::Effect>> m_effects;
        std::string m_name;
        friend changers::EntityChanger;
        friend changers::EffectChanger;
    public:
        virtual ~Entity() = default;

        explicit Entity(std::string name, std::map<int, int>);

        virtual std::vector<std::vector<char>> draw() final;

        virtual int get(int key) const final;
        virtual int getReal(int key) const final;
        virtual int get(Characteristic characteristic) const;

        virtual std::set<std::shared_ptr<effects::Effect>> getEffects() const final;

        virtual std::set<std::shared_ptr<Skill>> getSkills() const final;

        virtual std::string getName() const;

        virtual bool isAlive() const final;

        virtual bool isTurnable() const final;

        virtual int dodged() const final;

        virtual int resisted(int effectHash) const final;
    
    protected:
        virtual std::vector<std::vector<char>> drawAlive() = 0;
        virtual std::vector<std::vector<char>> drawDead();
    };
} // namespace entity
#endif //UNTITLED_ENTITY_H
