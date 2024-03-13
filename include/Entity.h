//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H
#include <set>
#include <memory>
#include <map>
#include <string>

#include "Skill.h"
#include "EntityChanger.h"
#include "Effect.h"
#include "Characteristic.h"

class Skill;
class EntityChanger;
class Effect;
class Entity{
protected:
    std::set<std::shared_ptr<Skill>> m_skills;
    std::map<std::size_t, int> m_characteristics;
    std::set<std::shared_ptr<Effect>> m_effects;
    std::string m_name;

    friend class EntityChanger;
public:
    Entity(std::map<size_t, int>);
    std::vector<std::vector<char>> draw();
    virtual int get(size_t key) const;
    virtual int get(Characteristic characteristic) const;
    const std::set<std::shared_ptr<Effect>>& getEffects() const;
    const std::set<std::shared_ptr<Skill>>& getSkills() const;
    virtual std::string getName() const;
    virtual bool isAlive() const final;
    virtual bool isTurnable() const final;
    virtual int dodged() const final;
    virtual int resisted(size_t effectHash) const final;
};
#endif //UNTITLED_ENTITY_H