//
// Created by artem on 16.03.2024.
//

#ifndef CPPDUNGEON_EVENTFACTORY_H
#define CPPDUNGEON_EVENTFACTORY_H
#include <map>
#include <set>
#include <string>
#include "eventCreator.h"
#include <vector>
template <class Base, class IdType>
class ObjectFactory
{
protected:
    typedef AbstractCreator<Base> AbstractFactory;
    typedef std::map<IdType, AbstractFactory*> FactoryMap;
    FactoryMap	m_factory;

public:
    ObjectFactory() {}
    virtual ~ObjectFactory();
    FactoryMap getFactoryMap() {
        return m_factory;
    }
    template <class C>
    void add(const IdType & id)
    {
        registerClass(id, new Creator<C, Base>());
    }

    Base * create(const IdType   & id)
    {
        typename FactoryMap::iterator it = m_factory.find(id);
        if (it != m_factory.end())
            return it->second->create();
        return 0;
    }

protected:
    void registerClass(const IdType & id, AbstractFactory * p)
    {
        typename FactoryMap::iterator it = m_factory.find(id);
        if (it == m_factory.end())
            m_factory[id] = p;
        else
            delete p;
    }
};
#endif //CPPDUNGEON_EVENTFACTORY_H
