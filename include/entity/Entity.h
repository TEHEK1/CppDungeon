//
// Created by Амир Кашапов on 24.02.2024.
//
#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>


#include "skillDesigns/Skill.h"
#include "Characteristic.h"
#include "effects/Effect.h"

class Skill;
namespace changers {
    class EntityChanger;
} // namespace changers
class Entity{
protected:
    std::set<std::shared_ptr<Skill>> m_skills;
    std::map<std::size_t, int> m_characteristics;
    std::set<std::shared_ptr<effects::Effect>> m_effects;
    std::string m_name;
    friend changers::EntityChanger;
public:
    virtual ~Entity() = default;
    explicit Entity(std::map<size_t, int>);
    std::vector<std::vector<char>> draw();
    virtual int get(size_t key) const;
    virtual int get(Characteristic characteristic) const;
    const std::set<std::shared_ptr<effects::Effect>>& getEffects() const;
    const std::set<std::shared_ptr<Skill>>& getSkills() const;
    virtual std::string getName() const;
    virtual bool isAlive() const final;
    virtual bool isTurnable() const final;
    virtual int dodged() const final;
    virtual int resisted(size_t effectHash) const final;
};
#endif //UNTITLED_ENTITY_H
