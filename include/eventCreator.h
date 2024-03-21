//
// Created by artem on 16.03.2024.
//

#ifndef CPPDUNGEON_CREATIR_H
#define CPPDUNGEON_CREATIR_H
#include "abstractEventCreator.h"
template <class Object, class Base>
class Creator: public AbstractCreator<Base>
{
public:
    Creator() { }
    virtual ~Creator()	{}
    std::shared_ptr<Base> create() const { return std::make_shared<Object>(); }
};
#endif //CPPDUNGEON_CREATIR_H
